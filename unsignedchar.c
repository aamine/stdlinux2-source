#include <stdio.h>
#include <stdlib.h>

char
f_char(void)
{
    return 128;
}

unsigned char
f_uchar(void)
{
    return 128;
}

int
f_int(void)
{
    return 128;
}

int
main(int argc, char *argv[])
{
    char c;

    c = f_char();
    printf("char\t%d\n", (int)c);
    c = f_uchar();
    printf("uchar\t%d\n", (int)c);
    c = f_int();
    printf("int\t%d\n", (int)c);

    exit(0);
}
