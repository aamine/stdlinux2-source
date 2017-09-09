#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#ifndef HZ
# define HZ 60
#endif
#define clock2sec(c) ((double)(c / HZ))

int
main(int argc, char *argv[])
{
    struct tms t;

    if (times(&t) < 0) {
        perror("times(2)");
        exit(1);
    }
    printf("u =%f\n", clock2sec(t.tms_utime));
    printf("s =%f\n", clock2sec(t.tms_stime));
    printf("cu=%f\n", clock2sec(t.tms_cutime));
    printf("cs=%f\n", clock2sec(t.tms_cstime));
    exit(0);
}
