#ifdef LARGEFILE
# define _FILE_OFFSET_BITS 64
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <sys/acct.h>

int
main(int argc, char *argv[])
{
    printf("char      = %lu\n", (unsigned long)sizeof(char));
    printf("short     = %lu\n", (unsigned long)sizeof(short));
    printf("int       = %lu\n", (unsigned long)sizeof(int));
    printf("long      = %lu\n", (unsigned long)sizeof(long));
    printf("long long = %lu\n", (unsigned long)sizeof(long long));
    printf("void*     = %lu\n", (unsigned long)sizeof(void*));
    puts("");
    printf("caddr_t   = %lu\n", (unsigned long)sizeof(caddr_t));
    printf("clock_t   = %lu\n", (unsigned long)sizeof(clock_t));
    printf("comp_t    = %lu\n", (unsigned long)sizeof(comp_t));
    printf("dev_t     = %lu\n", (unsigned long)sizeof(dev_t));
    printf("fpos_t    = %lu\n", (unsigned long)sizeof(fpos_t));
    printf("gid_t     = %lu\n", (unsigned long)sizeof(gid_t));
    printf("ino_t     = %lu\n", (unsigned long)sizeof(ino_t));
    printf("mode_t    = %lu\n", (unsigned long)sizeof(mode_t));
    printf("nlink_t   = %lu\n", (unsigned long)sizeof(nlink_t));
    printf("off_t     = %lu\n", (unsigned long)sizeof(off_t));
    printf("pid_t     = %lu\n", (unsigned long)sizeof(pid_t));
    printf("ptrdiff_t = %lu\n", (unsigned long)sizeof(ptrdiff_t));
    printf("rlim_t    = %lu\n", (unsigned long)sizeof(rlim_t));
    printf("size_t    = %lu\n", (unsigned long)sizeof(size_t));
    printf("ssize_t   = %lu\n", (unsigned long)sizeof(ssize_t));
    printf("time_t    = %lu\n", (unsigned long)sizeof(time_t));
    printf("uid_t     = %lu\n", (unsigned long)sizeof(uid_t));
    printf("wchar_t   = %lu\n", (unsigned long)sizeof(wchar_t));
    exit(0);
}
