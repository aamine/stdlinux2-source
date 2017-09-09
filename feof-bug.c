#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 16

int
main(int argc, char *argv[])
{
    FILE *f = stdin;
    char buf[MAXLINE + 1];

    while (!feof(f)) {
        fgets(buf, MAXLINE, f);
        fputs(buf, stdout);
    }
    exit(0);
}
