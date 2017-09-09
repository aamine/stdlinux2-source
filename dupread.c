#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void
readshow(int fd)
{
    char buf[8];
    int n;

    n = read(fd, buf, 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    if (n == 0)
        exit(0);
    switch (buf[0]) {
      case ' ': strcpy(buf, "' '"); break;
      case '\n': strcpy(buf, "\\n"); break;
      case '\r': strcpy(buf, "\\r"); break;
      case '\t': strcpy(buf, "\\t"); break;
      case '\v': strcpy(buf, "\\v"); break;
      default:
        buf[1] = '\0';
        break;
    }
    printf("fd%d: %s\n", fd, buf);
}

int
main(int argc, char *argv[])
{
    int newfd;

    newfd = dup(0);
    for (;;) {
        readshow(0);
        readshow(newfd);
    }
    exit(0);
}
