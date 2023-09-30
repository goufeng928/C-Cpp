//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//判断X是否存在于Arr数组中。
int array_x_in_arr_int(int value, int* arr, int rows_num) {

    int amount = 0;
    int i = 0;

    while (i < rows_num && amount < 1) {
        if (value == arr[i]) amount += 1;
        i++;
    }
    return amount;
}