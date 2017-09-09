#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>

struct linux_dirent {
    long d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[];
    /*
    char pad;
    char d_type;
    */
};

#ifdef PRETTY_PRINT
static void print_dirents(char *buf, size_t len);
#endif

int
main(int argc, char *argv[])
{
    int fd;
    
    if (argc < 2) {
        fprintf(stderr, "missing dirname\n");
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror(argv[1]);
        exit(1);
    }
    for (;;) {
        char buf[1024];
        int n;
        
        n = syscall(__NR_getdents, fd, buf, sizeof buf);
        if (n < 0) {
            perror("getdents(2)");
            exit(1);
        }
        if (n == 0) break;
#ifdef PRETTY_PRINT
        print_dirents(buf, n);
#else
        write(STDOUT_FILENO, buf, n);
#endif
    }
    exit(0);
}

#ifdef PRETTY_PRINT
static void
print_dirents(char *buf, size_t len) {
    int offset;

    for (offset = 0; offset < len; ) {
        struct linux_dirent *ent = (struct linux_dirent*)(buf + offset);
        printf("d_ino=%ld, d_off=%ld, d_reclen=%u, d_name=%s\n", ent->d_ino, (long)ent->d_off, (unsigned int)ent->d_reclen, ent->d_name);
        offset += ent->d_reclen;
    }
}
#endif
