#include "stdio.h"
#include "stdlib.h"
#define N 5

int main() {
    int* arr = (int*)malloc(sizeof(int)*N);

    for(int i = 0; i < N; i++) {
        arr[i] = i * i;
    }

    for(int i = 0; i < N; i++) {
        printf("\n%d", arr[i]);
    }

    free(arr);
    arr = NULL;
    for(int i = 0; i < N; i++) {
        printf("\n%d", arr[i]);
    }
}
