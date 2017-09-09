#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int
main(int argc, char *argv[])
{
    struct passwd *pw;

    if (argc < 2) {
        fprintf(stderr, "no argument\n");
        exit(1);
    }
    pw = getpwnam(argv[1]);
    if (!pw) {
        perror(argv[1]);
        exit(1);
    }
    printf("id=%d\n", pw->pw_uid);
    exit(0);
}
