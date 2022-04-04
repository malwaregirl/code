#include <stdio.h>

/* Define the type 'struct point', and declare a global variable g_point with fields x = 10, y = 5 */
struct point {
    int x;
    int y;
} g_point = {
        .x = 10,
        .y = 5,
};


/* Define a typedef of type s named s */
typedef struct s {
    const char *str;
    int (*fp)(int, int); /* Function pointer as a member */
} s;

int add(int x, int y) {
    return x + y;
}

int main(void) {
    printf("%d\n%d\n", g_point.x, g_point.y);

    s w1 = {
            .str = "World",
            .fp = add, /* w1.fp points to to function add */
    };

    printf("w1.str:\t%s\nsizeof(w1.str):\t%llu\nsizeof(w1):\t%llu\nsizeof(w1.fp):\t%llu\n",
           w1.str, sizeof(w1.str), sizeof(w1), sizeof(w1.fp));
    printf("%p\n%p\n", w1.fp, add);

    return 0;
}