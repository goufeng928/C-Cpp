//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//删除无序数组中元素的重复项，只保留唯一值，并返回剩余行数。
int array_unsort_delete_duplicate_int(int* source_arr, int rows_num) {

    int new_arr[2000] = {0};
    int k = 0, skip = 0;

    for (int i = 0; i < rows_num; i++) {

        //定义一个循环体内的临时变量，当对比值存在时，加1。
        int exist = 0;

        //当for循环中原始数组取到第i个元素，马上for循环对照数组，逐一对比是否有相等的值。
        for (int j = 0; j < 2000; j++) {
            if (source_arr[i] == new_arr[j]) exist += 1;
        }

        if (exist == 0) {
            new_arr[k] = source_arr[i];
            /*
            printf("[Debugging: Array Unsort Delete Duplicate] When i = %d, "
                   "source_arr: ( %d ) new_arr[ k = %d ]: ( %d ) rows_num: ( %d )\n",
                   i, source_arr[i], k, new_arr[k], rows_num); //调试打印。
            */
            k += 1; //k值每次都是在赋值后变化，所以k值最后恰好等于数组长度。
        } else if (exist > 0) {
            skip += 1;
            /*
            printf("[Debugging: Array Unsort Delete Duplicate] When i = %d, "
                   "source_arr: ( %d ) new_arr[ k = %d ]: ( %d ) rows_num: ( %d )\n",
                   i, source_arr[i], k, new_arr[k], rows_num); //调试打印。
            */
        }
    }
    printf("[ Function ] Unsort Array Delete Duplicate: Finished, Distinct %d Row.\n", k);

    return k;
}