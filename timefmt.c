#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <locale.h>

int
main(int argc, char *argv[])
{
    time_t t;
    struct tm *tm;
    struct timeval tv;

    setlocale(LC_TIME, "");

    /* time(2), ctime(3), gettimeofday(2) */
    time(&t);
    gettimeofday(&tv, NULL);
    printf("time         = %ld\n", (long)t);
    printf("ctime        = %s", ctime(&t));
    printf("tv.tv_sec    = %ld\n", (long)tv.tv_sec);
    printf("tv.tv_usec   = %ld\n", (long)tv.tv_usec);
    printf("ctime(tv)    = %s", ctime(&tv.tv_sec));

    /* gmtime(3), localtime(3) */
    tm = gmtime(&t);
    printf("asctime(UTC) = %s", asctime(tm));
    printf("mktime(UTC)  = %ld\n", (long)t);
    tm = localtime(&t);
    printf("asctime(LOC) = %s", asctime(tm));
    printf("mktime(LOC)  = %ld\n", (long)t);

    exit(0);
}
