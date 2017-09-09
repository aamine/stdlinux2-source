#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
    char buf[PATH_MAX];

    if (!getcwd(buf, PATH_MAX)) {
        perror("getcwd");
        exit(1);
    }
    puts(buf);
    exit(0);
}
