#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

sighandler_t
trap_signal(int sig, sighandler_t handler)
{
    struct sigaction act, old;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    if (sigaction(sig, &act, &old) < 0)
        return NULL;

    return old.sa_handler;
}

void
msg_sleep(int sig)
{
    puts("got SIGINT, sleep...");
    sleep(3);
}

int
main(int argc, char *argv[])
{
    trap_signal(SIGINT, msg_sleep);
    pause();
    exit(0);
}
