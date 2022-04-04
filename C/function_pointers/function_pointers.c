#include "stdio.h"
#include "../utils/utils.h"

#define SIZE 10

/* 
* pointer to a function taking two ints and returning an int.
*/
typedef int(*fp)(int, int);


int ascending(int a, int b) {
    return a < b;
}

int descending(int a, int b) {
    return a > b;
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(int len, int in[], fp order) {
    for(int i = 0; i < len; ++i) {
        int largest = in[i];
        for(int j = i; j < len; ++j) {
            if(order(in[j], largest)) {
                largest = in[j];
                swap(&in[i], &in[j]);
            }
        }
    }

}

int main(void) {
    int a[] = {0,1,2,3,6,5,6,3,8,9};

    sort(SIZE, a, ascending);
    for(int i = 0; i < SIZE; ++i)
        printf("%d\n", a[i]);

    sort(SIZE, a, descending);
    for(int i = 0; i < SIZE; ++i)
        printf("%d\n", a[i]);

    return 0;
}
