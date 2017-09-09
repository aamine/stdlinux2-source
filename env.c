#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int
main(int argc, char *argv[])
{
    char **p;

    for (p = environ; *p; p++) {
        printf("%s\n", *p);
    }
    exit(0);
}
