#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Convert between network and representation format for IPv4 and IPv6 addresses.

    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;

    // Convert to binary format.
    // pton: Presentation to Network format
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));

    // Convert to representation format
    // ntop: Network to Presentation format
    // ipv4
    char ip4[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

    printf("The ipv4 address is: %s\n", ip4);

    // ipv6
    char ip6[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);

    printf("The ipv6 address is: %s\n", ip6);

    return 0;
}