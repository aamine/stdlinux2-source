#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

static int segv = 0;
static jmp_buf env;

static int
read_address(unsigned long addr)
{
    return *((unsigned char*)addr);
}

static void
on_SIGSEGV(int sig)
{
    segv = 1;
    siglongjmp(env, 1);
}

static char *
getcmdline(char *prompt)
{
    static char buf[1024];

    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buf, sizeof buf, stdin)) {
        fprintf(stderr, "fgets failed\n");
        exit(1);
    }
    return buf;
}

int
main(int argc, char *argv[])
{
    char *line;

    signal(SIGSEGV, on_SIGSEGV);
    while (line = getcmdline("> ")) {
        if (sigsetjmp(env, 1) == 0) {
            printf("%d\n", read_address(strtoul(line, NULL, 10)));
        }
        else {
            if (segv) {
                printf("not allocated\n");
                segv = 0;
            }
        }
    }
    exit(0);
}
