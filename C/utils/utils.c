#include "utils.h"

#include <stdio.h>

// Swap values of x and y using xor to avoid using a temporary variable.
void swapxor(int x, int y) {
    x ^= y;
    y ^= x;
    x ^= y;
}

void swapc(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void copy(char *dest, const char *src, int len) {
    for (int i = 0; i < len; ++i)
        dest[i] = src[i];
}

void reverse(char *s, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            swapc(&s[i], &s[j]);
        }
    }
}
