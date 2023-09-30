//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//删除有序数组中元素的重复项，只保留唯一值，并返回剩余行数。
int array_sorted_delete_duplicate_int(int* stu_member, int rows_num) {

    /***************Step1: Bubblesort***************/
    int temp_for_sort, skip = 0;

    //外层循环: 确保循环次数。
    for (int i=0; i <= rows_num; i++) {
        //内层循环: 对比每两行数据并交换位置。
        for (int j=0, k=1; j <= (rows_num-2) || k <= (rows_num-1); j++, k++) {
            if (stu_member[j] == stu_member[k]) {
                skip += 1;
            } else if (stu_member[j] > stu_member[k]) {
                temp_for_sort = stu_member[j];
                stu_member[j] = stu_member[k];
                stu_member[k] = temp_for_sort;
            }
        }
        //内层循环: 结束。
    }
    //外层循环: 结束。
    /***********************************************/

    /***************step2: Delete Duplicates***************/
    if (rows_num == 0 || rows_num == 1) {
        printf("[ Function ] "
               "Sorted Array Delete Duplicate: Finished, Distinct %d Row\n",rows_num);
        return rows_num;
    } else {
        // 删除重复项。
        int start = 0;
        int end = 1;
        int dst = 0;

        while (end < rows_num) {
            if (stu_member[start] != stu_member[end]) {
                stu_member[dst] = stu_member[start];
                start++;
                end++;
                dst++;
            } else {
                start++;
                end++;
            }
        }

        // 考虑End已经越界的时候
        stu_member[dst] = stu_member[start];
        dst += 1;

        printf("[ Function ] "
               "Sorted Array Delete Duplicate: Finished, Distinct %d Row\n",dst);
        return dst;
    }
    /******************************************************/

}