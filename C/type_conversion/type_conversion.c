#include <stdio.h>

void print_value(void *p) {
    printf("%d\n", *(int *) p);
}

int main(void) {
    int a, b;
    a = 20;
    void *vp;
    // The value of vp is the address of a
    vp = &a;

    // First we convert vp to an int* then we dereference it to get the value of a.
    b = *(int *) vp;
    printf("a: %d\nb: %d\n", a, b);

    print_value(vp);
    return 0;
}