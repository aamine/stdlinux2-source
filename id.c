#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static char * user_name(uid_t id);
static char * group_name(gid_t id);

int
main(int argc, char *argv[])
{
    uid_t u;
    gid_t g;
    char *name;
    gid_t *buf;
    long group_max;
    int n;
    char *comma;
    long i;

    u = getuid();
    printf("uid=%d", u);
    if (name = user_name(u)) {
        printf("(%s)", name);
    }

    g = getgid();
    printf(" gid=%d", g);
    if (name = group_name(g)) {
        printf("(%s)", name);
    }

    group_max = sysconf(_SC_NGROUPS_MAX);
    buf = malloc(sizeof(gid_t) * group_max);
    if (!buf) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    n = getgroups(group_max, buf);
    if (n < 0) {
        perror("getgroups");
        exit(1);
    }
    printf(" groups=");
    comma = "";
    for (i = 0; i < n; i++) {
        printf("%s%d(%s)", comma, buf[i], group_name(buf[i]));
        comma = ",";
    }
    printf("\n");

    exit(0);
}

static char *
user_name(uid_t id)
{
    struct passwd *pw;

    pw = getpwuid(id);
    if (!pw) return NULL;
    return pw->pw_name;
}

static char *
group_name(gid_t id)
{
    struct group *gr;

    gr = getgrgid(id);
    if (!gr) return NULL;
    return gr->gr_name;
}
