#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
char *str1 = "Hello, World!\n";
char buf[14] = { 72, 101, 108, 108, 111, 44, 32,
                 87, 111, 114, 108, 100, 33, 10 };
char *str2 = buf;

    printf("%s", str1);
    printf("%s", str2);
    exit(0);
}
