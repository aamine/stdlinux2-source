#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        char *val = getenv(argv[i]);
        if (val) printf("%s\n", val);
    }
    exit(0);
}
