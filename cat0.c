#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int fd;
    unsigned char buf[BUFSIZ];
    int n;

    fd = open(argv[1], O_RDONLY);
    for (;;) {
        n = read(fd, buf, BUFSIZ);
        if (n == 0) break;
        n = write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    exit(0);
}
