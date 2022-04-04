#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>

// The memory of the union is large enough to hold the largest member of the union
// the union can only have one value at a time
union U {
    int a;
    char b[20];
    struct union_member_struct {
        char s[40];
    } member_struct;
} u;


int main(void) {
    u.a = 10;
    printf("u.a:\t\t%d\n", u.a);

    strncpy_s(u.b, sizeof(u.b), "Hello, world!", sizeof(u.b));
    printf("u.b:\t\t%s\nu.a:\t\t%d\nsizeof(u):\t\t%lu\n", u.b, u.a, sizeof(u));
    printf("Address of u:\t\t%p\nAddress of u.a:\t\t%p\nAddress of u.b:\t\t%p\n", &u, &u.a, &u.b);

    return 0;
}