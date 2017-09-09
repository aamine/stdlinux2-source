#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s%s", (i==1?"":" "), argv[i]);
    }
    putchar('\n');
    exit(0);
}
