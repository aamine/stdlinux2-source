/*
    daytimed.c -- Simple daytime server.

    Copyright (c) 2005 Minero Aoki

    This program is free software.
    Redistribution and use in source and binary forms,
    with or without modification, are permitted.
*/

#if defined(__digital__) && defined(__unix__)
# ifdef _XOPEN_SOURCE
#  undef _XOPEN_SOURCE
# endif
# define _XOPEN_SOURCE 500
# define _OSF_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DEFAULT_PORT 13

static int listen_socket(int port);

int
main(int argc, char *argv[])
{
    struct sockaddr_storage addr;
    socklen_t addrlen = sizeof addr;
    int sock, server;
    time_t t;
    struct tm *tm;
    char *timestr;
    
    server = listen_socket(argc > 1 ? atoi(argv[1]) : DEFAULT_PORT);
    sock = accept(server, (struct sockaddr*)&addr, &addrlen);
    if (sock < 0) {
        perror("accept(2)");
        exit(1);
    }
    time(&t);
    tm = localtime(&t);
    timestr = asctime(tm);
    write(sock, timestr, strlen(timestr));
    close(sock);
    close(server);
    exit(0);
}

static int
listen_socket(int port)
{
    struct addrinfo hints, *res, *ai;
    int err;
    char service[16];

    memset(&hints, 0, sizeof(struct addrinfo));
    /* hints.ai_family = AF_UNSPEC; */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    snprintf(service, sizeof service, "%d", port);
    if ((err = getaddrinfo(NULL, service, &hints, &res)) != 0) {
        fprintf(stderr, "%s\n", gai_strerror(err));
        exit(1);
    }
    for (ai = res; ai; ai = ai->ai_next) {
        int sock;

        sock = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (sock < 0) continue;
        if (bind(sock, ai->ai_addr, ai->ai_addrlen) < 0) {
            close(sock);
            continue;
        }
        if (listen(sock, 5) < 0) {
            close(sock);
            continue;
        }
        freeaddrinfo(res);
        fprintf(stderr, "listening on port %d...\n", port);
        return sock;
    }
    fprintf(stderr, "cannot listen socket\n");
    exit(1);
}
