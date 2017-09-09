#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "%s: wrong arguments\n", argv[0]);
        exit(1);
    }
    if (link(argv[1], argv[2]) < 0) {
        perror(argv[1]);
        exit(1);
    }
    exit(0);
}
