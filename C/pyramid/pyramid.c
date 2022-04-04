#include <stdio.h>
#define HEIGHT 10
#define WIDTH 30
int main(void) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", j >= (WIDTH - i * 2) / 2 && j <= (WIDTH + i * 2) / 2 ? 'x' : ' ');
        }
        printf("\n");
    }
    return 0;
}
