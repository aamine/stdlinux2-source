#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int
main(int argc, char *argv[])
{
    openlog("xxxx", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "test message");
    exit(0);
}
