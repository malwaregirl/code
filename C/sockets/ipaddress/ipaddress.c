#define __STDC_WANT_LIB_EXT1__ 1
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Not enough arguments.\n");
        exit(0);
    }

    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;// This will point to the results

    int err = memset_s(&hints, sizeof hints, 0, sizeof hints);// Make sure the struct is empty
    hints.ai_family = AF_UNSPEC;    // Unspecified. Family can be IPv4 or IPv6.
    hints.ai_socktype = SOCK_STREAM;// Set socket type to TCP.
    hints.ai_flags = AI_PASSIVE;    // Fill in IP for me.

    if ((status = getaddrinfo(argv[1], "http", &hints, &servinfo)) != NULL) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    struct addrinfo *p;
    for (p = servinfo; p != servinfo->ai_next; p = servinfo->ai_next) {
        void *addr = NULL;          // IP address
        unsigned short int port = 0;// Port number
        char *ipver = NULL;

        if (p->ai_family == AF_INET) {// IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
            addr = &(ipv4->sin_addr);
            port = ipv4->sin_port;
            ipver = "IPv4";
        } else if (p->ai_family == AF_INET6) {// IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) p->ai_addr;
            addr = &(ipv6->sin6_addr);
            port = ipv6->sin6_port;
            ipver = "IPv6";
        }

        char ipstr[INET6_ADDRSTRLEN];
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s:\t  %s\t(%s)\tport: %d\n", argv[1], ipstr, ipver, port);
    }

    freeaddrinfo(servinfo);

    return 0;
}