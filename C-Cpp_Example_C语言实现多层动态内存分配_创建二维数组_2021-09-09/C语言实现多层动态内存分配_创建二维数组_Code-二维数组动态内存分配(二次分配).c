#include "stdio.h"
#include "stdlib.h"
#define m 5
#define n 4

int main() {

    int** arr = (int**)malloc(sizeof(int*)*m);

    for (int i = 0; i < m; ++i) {
        arr[i] = (int*)malloc(sizeof(int*)*n);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 99;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("\n%d",arr[i][j]);
        }
    }
}
