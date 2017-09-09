#include <stdio.h>
#include <stdlib.h>

extern int a(void);
extern int b(void);

int
main(int argc, char **argv)
{
    a();
    b();
    exit(0);
}
