#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    strncpy(argv[0], "PROGRAM_NAME", strlen(argv[0]));
    pause();
    exit(0);
}
