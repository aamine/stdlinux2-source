#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s secs\n", argv[0]);
        exit(1);
    }
    sleep(atoi(argv[1]));
    exit(0);
}
