//
// Created by GF on 2023/2/22.
//

#include <stdio.h>
#include <malloc.h>

//读取CSV文件数据到动态内存数组。
void csv_to_memory_by_getc(int** arr, const char* csv_path) {

    FILE* fp;
    //malloc分配空间地址后返回的是一个指针。
    *arr = malloc(sizeof(int));
    int ch_ascii, i = 0, memory_size, len;

    //CSV文件需要转换成GBK或GB2312编码，否则中文输出为乱码。
    fp = fopen(csv_path, "r");

    if (fp == NULL) {
        printf("[ Function ] CSV To Memory: Open CSV Failed.\n");
    }
    else {
        printf("[ Function ] CSV To Memory: Open CSV Successful.\n");

        while ((ch_ascii = getc(fp)) != EOF) {
            //因为malloc分配空间地址后返回的是一个指针，所以要将"*arr"括起来，以免"*"变成指针的取值符号。
            (*arr)[i] = ch_ascii;
            //分配一个全新的内存空间。
            (*arr) = realloc((*arr), (i+2)*(sizeof(int)));
            //每次把最终分配的内存大小保存在MemorySize变量内。
            memory_size = (i+2)*(sizeof(int));
            i++;
        }
        printf("[ Function ] CSV To Memory: Finished.\n");

        //算出数组的长度，这里只是做个示例，实际可以直接使用i变量，i变量已经增量为数组长度。
        len = memory_size/sizeof(int);
    }
    fclose(fp);

}