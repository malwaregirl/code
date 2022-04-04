#define __STDC_WANT_LIB_EXT1__ 1
#include <netdb.h>
#include <sys/socket.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof hints);// Make sure hints is set to 0.
    hints.ai_family = AF_UNSPEC;    // Either IPv4 or IPv6.
    hints.ai_socktype = SOCK_STREAM;// TCP.
    hints.ai_flags = AI_PASSIVE;    // Fill in ip for me.

    int status;
    if ((status = getaddrinfo(NULL, "3490", &hints, &res)) != NULL) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    struct addrinfo *p;
    for (p = res; p != NULL; p = res->ai_next) {
        if (p == res->ai_next)
            break;
    }

    int socketfd;
    // set socketfd to the file descriptor of the new socket.
    if (!(socketfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol))) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    if (bind(socketfd, res->ai_addr, res->ai_addrlen) != NULL) {
        fprintf(stderr, "bind error: %d\n", errno);
        exit(errno);
    }

    freeaddrinfo(res);

    return 0;
}
