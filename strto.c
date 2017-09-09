#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
    long n;
    unsigned long u;
    
    if (argc < 2) {
        puts("no argument");
        exit(1);
    }
    errno = 0;
    n = strtol(argv[1], NULL, 10);
    printf("strtol(%s) = %ld\n", argv[1], n);
    if (errno == 0) {
        printf("errno == 0\n");
    }
    else if (errno == ERANGE) {
        printf("errno == ERANGE\n");
    }
    else {
        printf("errno == %d\n", errno);
    }

    errno = 0;
    u = strtoul("-1", NULL, 10);
    printf("strtoul(\"-1\") = %lu\n", u);
    printf("errno == %d\n", errno);
    u = strtoul("-3", NULL, 10);
    printf("strtoul(\"-3\") = %lu\n", u);
    u = (unsigned long)(-1L);
    printf("(unsigned long)(-1L) = %lu\n", u);

    exit(0);
}
