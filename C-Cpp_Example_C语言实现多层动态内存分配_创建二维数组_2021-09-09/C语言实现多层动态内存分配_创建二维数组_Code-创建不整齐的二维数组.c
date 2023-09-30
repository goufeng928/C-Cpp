#include "stdio.h"
#include "stdlib.h"
#define m 5
#define n 4

int main() {
    int** arr = (int**)malloc(sizeof(int*)*m);

    arr[0] = (int*)malloc(sizeof(int*)*1);
    arr[1] = (int*)malloc(sizeof(int*)*2);
    arr[2] = (int*)malloc(sizeof(int*)*3);
    arr[3] = (int*)malloc(sizeof(int*)*4);
    arr[4] = (int*)malloc(sizeof(int*)*5);

    for (int i = 0; i < 1; i++) {
        arr[0][i] = 9;
    }
    for (int i = 0; i < 2; i++) {
        arr[1][i] = 9;
    }
    for (int i = 0; i < 3; i++) {
        arr[2][i] = 9;
    }
    for (int i = 0; i < 4; i++) {
        arr[3][i] = 9;
    }
    for (int i = 0; i < 5; i++) {
        arr[4][i] = 9;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i+1; ++j) {
            arr[i][j] = 99;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i+1; ++j) {
            printf("\n%d", arr[i][j]);
        }
    }
}
