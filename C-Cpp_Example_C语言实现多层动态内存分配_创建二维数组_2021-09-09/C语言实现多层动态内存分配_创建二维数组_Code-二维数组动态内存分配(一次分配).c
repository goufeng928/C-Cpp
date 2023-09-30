#include "stdio.h"
#include "stdlib.h"
#define m 5
#define n 4

int main() {
    int* arr = (int*)malloc(sizeof(int)*m*n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i*n + j] = 99;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("\n%d", arr[i*n + j]);
        }
    }

}
