#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int c;

    if ((argc > 2) && (argv[1][0] == 'f')) {
        while ((c = fgetc(stdin)) != EOF)
            ;
    }
    else {
        while ((c = getc(stdin)) != EOF)
            ;
    }
    exit(0);
}
