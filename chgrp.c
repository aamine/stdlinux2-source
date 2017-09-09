/*
    Usage: chgrp <group> <file>...

    <user> must be a group name.  Group ID is not supported.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

static gid_t get_group_id(char *group);

int
main(int argc, char *argv[])
{
    gid_t gid;
    int i;

    if (argc < 2) {
        fprintf(stderr, "no group name given\n");
        exit(1);
    }
    gid = get_group_id(argv[1]);
    for (i = 2; i < argc; i++) {
        if (chown(argv[i], -1, gid) < 0) {
            perror(argv[i]);
        }
    }
    exit(1);
}

static gid_t
get_group_id(char *group)
{
    struct group *gr;

    gr = getgrnam(group);
    if (!gr) {
        fprintf(stderr, "no such group: %s\n", group);
        exit(1);
    }
    return gr->gr_gid;
}
