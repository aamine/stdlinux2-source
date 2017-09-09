#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char buf[1024];
    size_t st;

    st = fread(buf, 1, 1024, stdin);
    printf("fread() result=%ld\n", st);
    printf("eof=%d, error=%d\n", feof(stdin), ferror(stdin));
    exit(0);
}
