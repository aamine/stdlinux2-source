/*
    Usage: chown <user> <file>...

    <user> must be a user name.  User ID is not supported.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

static uid_t get_user_id(char *user);

int
main(int argc, char *argv[])
{
    uid_t uid;
    int i;

    if (argc < 2) {
        fprintf(stderr, "no user name given\n");
        exit(1);
    }
    uid = get_user_id(argv[1]);
    for (i = 2; i < argc; i++) {
        if (chown(argv[i], uid, -1) < 0) {
            perror(argv[i]);
        }
    }
    exit(1);
}

static uid_t
get_user_id(char *user)
{
    struct passwd *pw;

    pw = getpwnam(user);
    if (!pw) {
        fprintf(stderr, "no such user: %s\n", user);
        exit(1);
    }
    return pw->pw_uid;
}
