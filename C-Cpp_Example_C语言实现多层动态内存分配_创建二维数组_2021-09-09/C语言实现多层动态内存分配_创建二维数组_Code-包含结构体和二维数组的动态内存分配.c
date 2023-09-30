#include "stdio.h"
#include "stdlib.h"
#define m 5
#define n 4

typedef struct {
    int** sums;
    int sumsSize;
} NumMatrix;

int main() {
    int row = 5;
    int col[5] = {1, 2, 3, 4, 5};

    NumMatrix* ret = (NumMatrix*)malloc(sizeof(NumMatrix));
    ret->sums = (int **)malloc(sizeof(int*)*row);

    for (int i = 0; i < row; ++i) {
        ret->sums[i] = (int*)malloc(sizeof(int)*col[i]);
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col[i]; ++j) {
            ret->sums[i][j] = 99;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col[i]; ++j) {
            printf("\n%d", ret->sums[i][j]);
        }
    }
}
