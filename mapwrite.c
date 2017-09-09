#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define DATAFILE "mapwrite.data"

int
main(int argc, char *argv[])
{
    int fd;
    char *ptr;
    int len = 3;

    /* prepare data file */
    unlink(DATAFILE);   /* ignore error */
    fd = open(DATAFILE, O_WRONLY|O_CREAT, 0666);
    if (fd < 0) {
        perror(DATAFILE);
        exit(1);
    }
    write(fd, "NO\n", 3);
    close(fd);

    /* write by mmap */
    fd = open(DATAFILE, O_RDWR);
    if (fd < 0) {
        perror(DATAFILE);
        exit(1);
    }
    ptr = (char*)mmap(0, len, PROT_WRITE, MAP_SHARED, fd, 0);
    if (!ptr) {
        perror("mmap(2)");
        exit(1);
    }
    close(fd);
    ptr[0] = 'O';
    ptr[1] = 'K';
    ptr[2] = '\n';
    munmap(ptr, len);

    /* cat it */
    system("cat " DATAFILE);

    exit(0);
}
