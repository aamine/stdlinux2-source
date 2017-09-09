#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

struct cmd {
    int argc;
    char **argv;
    int capa;
    int status;
    int pid;
    struct cmd *next;
};

#define REDIRECT_P(cmd) ((cmd)->argc == -1)
#define PID_BUILTIN -2
#define BUILTIN_P(cmd) ((cmd)->pid == PID_BUILTIN)

struct builtin {
    char *name;
    int (*f)(int argc, char *argv[]);
};

static void prompt(void);
static int invoke_commands(struct cmd *cmd);
static void exec_pipeline(struct cmd *cmdhead);
static void redirect_stdout(char *path);
static int wait_pipeline(struct cmd *cmdhead);
static struct cmd* pipeline_tail(struct cmd *cmdhead);
static struct cmd* parse_command_line(char *cmdline);
static void free_cmd(struct cmd *p);
static struct builtin* lookup_builtin(char *name);
static int builtin_cd(int argc, char *argv[]);
static int builtin_pwd(int argc, char *argv[]);
static int builtin_exit(int argc, char *argv[]);
static void* xmalloc(size_t sz);
static void* xrealloc(void *ptr, size_t sz);

static char *program_name;

int
main(int argc, char *argv[])
{
    program_name = argv[0];
    for (;;) {
        prompt();
    }
    exit(0);
}

#define LINEBUF_MAX 2048

static void
prompt(void)
{
    static char buf[LINEBUF_MAX];
    struct cmd *cmd;

    fprintf(stdout, "$ ");
    fflush(stdout);
    if (fgets(buf, LINEBUF_MAX, stdin) == NULL)
        exit(0);
    cmd = parse_command_line(buf);
    if (cmd == NULL) {
        fprintf(stderr, "%s: syntax error\n", program_name);
        return;
    }
    if (cmd->argc > 0)
        invoke_commands(cmd);
    free_cmd(cmd);
}

static int
invoke_commands(struct cmd *cmdhead)
{
    int st;
    int original_stdin = dup(0);
    int original_stdout = dup(1);

    exec_pipeline(cmdhead);
    st = wait_pipeline(cmdhead);
    close(0); dup2(original_stdin, 0); close(original_stdin);
    close(1); dup2(original_stdout, 1); close(original_stdout);

    return st;
}

#define HEAD_P(cmd) ((cmd) == cmdhead)
#define TAIL_P(cmd) (((cmd)->next == NULL) || REDIRECT_P((cmd)->next))

static void
exec_pipeline(struct cmd *cmdhead)
{
    struct cmd *cmd;
    int fds1[2] = {-1, -1};
    int fds2[2] = {-1, -1};

    for (cmd = cmdhead; cmd && !REDIRECT_P(cmd); cmd = cmd->next) {
        fds1[0] = fds2[0];
        fds1[1] = fds2[1];
        if (! TAIL_P(cmd)) {
            if (pipe(fds2) < 0) {
                perror("pipe");
                exit(3);
            }
        }
        if (lookup_builtin(cmd->argv[0]) != NULL) {
            cmd->pid = PID_BUILTIN;
        }
        else {
            cmd->pid = fork();
            if (cmd->pid < 0) {
                perror("fork");
                exit(3);
            }
            if (cmd->pid > 0) { /* parent */
                if (fds1[0] != -1) close(fds1[0]);
                if (fds1[1] != -1) close(fds1[1]);
                continue;
            }
        }
        if (! HEAD_P(cmd)) {
            close(0); dup2(fds1[0], 0); close(fds1[0]);
            close(fds1[1]);
        }
        if (! TAIL_P(cmd)) {
            close(fds2[0]);
            close(1); dup2(fds2[1], 1); close(fds2[1]);
        }
        if ((cmd->next != NULL) && REDIRECT_P(cmd->next)) {
            redirect_stdout(cmd->next->argv[0]);
        }
        if (!BUILTIN_P(cmd)) {
            execvp(cmd->argv[0], cmd->argv);
            fprintf(stderr, "%s: command not found: %s\n",
                    program_name, cmd->argv[0]);
            exit(1);
        }
    }
}

static void
redirect_stdout(char *path)
{
    int fd;

    close(1);
    fd = open(path, O_WRONLY|O_TRUNC|O_CREAT, 0666);
    if (fd < 0) {
        perror(path);
        return;
    }
    if (fd != 1) {
        dup2(fd, 1);
        close(fd);
    }
}

static int
wait_pipeline(struct cmd *cmdhead)
{
    struct cmd *cmd;

    for (cmd = cmdhead; cmd && !REDIRECT_P(cmd); cmd = cmd->next) {
        if (BUILTIN_P(cmd))
            cmd->status = lookup_builtin(cmd->argv[0])->f(cmd->argc, cmd->argv);
        else
            waitpid(cmd->pid, &cmd->status, 0);
    }
    return pipeline_tail(cmdhead)->status;
}

static struct cmd*
pipeline_tail(struct cmd *cmdhead)
{
    struct cmd *cmd;

    for (cmd = cmdhead; !TAIL_P(cmd); cmd = cmd->next)
        ;
    return cmd;
}

#define INIT_ARGV 8
#define IDENT_CHAR_P(c) (!isspace((int)c) && ((c) != '|') && ((c) != '>'))

static struct cmd*
parse_command_line(char *p)
{
    struct cmd *cmd;

    cmd = xmalloc(sizeof(struct cmd));
    cmd->argc = 0;
    cmd->argv = xmalloc(sizeof(char*) * INIT_ARGV);
    cmd->capa = INIT_ARGV;
    cmd->next = NULL;
    while (*p) {
        while (*p && isspace((int)*p))
            *p++ = '\0';
        if (! IDENT_CHAR_P(*p))
            break;
        if (*p && IDENT_CHAR_P(*p)) {
            if (cmd->capa <= cmd->argc) {
                cmd->capa *= 2;
                cmd->argv = xrealloc(cmd->argv, cmd->capa);
            }
            cmd->argv[cmd->argc] = p;
            cmd->argc++;
        }
        while (*p && IDENT_CHAR_P(*p))
            p++;
    }
    if (cmd->capa <= cmd->argc) {
        cmd->capa += 1;
        cmd->argv = xrealloc(cmd->argv, cmd->capa);
    }
    cmd->argv[cmd->argc] = NULL;

    if (*p == '|' || *p == '>') {
        if (cmd == NULL || cmd->argc == 0) goto parse_error;
        cmd->next = parse_command_line(p + 1);
        if (cmd->next == NULL || cmd->next->argc == 0) goto parse_error;
        if (*p == '>') {
            if (cmd->next->argc != 1) goto parse_error;
            cmd->next->argc = -1;
        }
        *p = '\0';
    }

    return cmd;

  parse_error:
    if (cmd) free_cmd(cmd);
    return NULL;
}

static void
free_cmd(struct cmd *cmd)
{
    if (cmd->next != NULL)
        free_cmd(cmd->next);
    free(cmd->argv);
    free(cmd);
}

struct builtin builtins_list[] = {
    {"cd",      builtin_cd},
    {"pwd",     builtin_pwd},
    {"exit",    builtin_exit},
    {NULL,      NULL}
};

static struct builtin*
lookup_builtin(char *cmd)
{
    struct builtin *p;

    for (p = builtins_list; p->name; p++) {
        if (strcmp(cmd, p->name) == 0)
            return p;
    }
    return NULL;
}

static int
builtin_cd(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "%s: wrong argument\n", argv[0]);
        return 1;
    }
    if (chdir(argv[1]) < 0) {
        perror(argv[1]);
        return 1;
    }
    return 0;
}

static int
builtin_pwd(int argc, char *argv[])
{
    char buf[PATH_MAX];

    if (argc != 1) {
        fprintf(stderr, "%s: wrong argument\n", argv[0]);
        return 1;
    }
    if (!getcwd(buf, PATH_MAX)) {
        fprintf(stderr, "%s: cannot get working directory\n", argv[0]);
        return 1;
    }
    printf("%s\n", buf);
    return 0;
}

static int
builtin_exit(int argc, char *argv[])
{
    if (argc != 1) {
        fprintf(stderr, "%s: too many arguments\n", argv[0]);
        return 1;
    }
    exit(0);
}

static void*
xmalloc(size_t sz)
{
    void *p;

    p = calloc(1, sz);
    if (!p)
        exit(3);
    return p;
}

static void*
xrealloc(void *ptr, size_t sz)
{
    void *p;

    if (!ptr) return xmalloc(sz);
    p = realloc(ptr, sz);
    if (!p)
        exit(3);
    return p;
}
