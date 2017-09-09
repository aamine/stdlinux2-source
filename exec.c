#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

static void
die(char *msg)
{
    printf("--- %s error ---\n", msg);
    exit(1);
}

int
main(int argc, char *argv[])
{
    puts("<<execl>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        execl("./args", "PROGNAME", "called by execl", NULL);
        die("execl");
    }

    puts("<<execlp>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        execlp("./args", "PROGNAME", "called by execlp", NULL);
        die("execlp");
    }

    puts("<<execle>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        execle("./args", "PROGNAME", "called by execle", NULL, environ);
        die("execle");
    }

    puts("<<execv>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        char *args[4] = { "PROGNAME", "called by execv", NULL };
        execv("./args", args);
        die("execv");
    }

    puts("<<execvp>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        char *args[4] = { "PROGNAME", "called by execvp", NULL };
        execvp("./args", args);
        die("execvp");
    }

    puts("<<execve>>");
    if (fork() != 0) {  /* parent */
        wait(NULL);
    }
    else {              /* child */
        char *args[4] = { "PROGNAME", "called by execve", NULL };
        execve("./args", args, environ);
        die("execve");
    }

    exit(0);
}
