#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char buf[1024];

    printf("HOST_NAME_MAX=%ld\n", sysconf(_SC_HOST_NAME_MAX));
    if (gethostname(buf, 1023) < 0) {
        fputs("gethostname failed???\n", stderr);
        exit(1);
    }
    printf("hostname=%s\n", buf);
    exit(0);
}
