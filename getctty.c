/*
    getctty.c

    Detouch controling tty then get tty again.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#if defined(__digital__) && defined(__unix__)
# define TTYPATH "/dev/tty01"
#else
# define TTYPATH "/dev/tty1"
#endif

int
main(int argc, char *argv[])
{
    pid_t id;
    int tty;

    puts("--- start ---");
    system("ps axj | grep getctty | grep -v grep");

    id = fork();
    if (id < 0) {
        perror("fork");
        exit(1);
    }
    if (id != 0) {
        _exit(0);
    }
    if (setsid() < 0) {
        perror("setsid");
        exit(1);
    }
    puts("--- ctty detouched ---");
    system("ps axj | grep getctty | grep -v grep");

    tty = open(TTYPATH, O_RDWR);
    if (tty < 0) {
        perror("open(" TTYPATH ")");
        exit(1);
    }
    puts("--- open OK ---");
    system("ps axj | grep getctty | grep -v grep");

    if (ioctl(tty, TIOCSCTTY, 1) < 0) {
        perror("ioctl(TIOCSCTTY)");
        exit(1);
    }
    puts("--- ioctl(TIOCSCTTY) OK ---");
    system("ps axj | grep getctty | grep -v grep");

    exit(0);
}
