//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//计数CSV文件内ASCII码(Int型)的数量。
int csv_count_ascii_int_byte_by_getc(const char* csv_path) {

    FILE *fp;
    int ch_ascii, num = 0;

    //CSV文件需要转换成GBK或GB2312编码，否则中文输出为乱码。
    fp = fopen(csv_path, "r");

    if (fp == NULL) {
        printf("[ Function ] CSV Count ASCII Int Byte: Open CSV Failed.\n");
    }
    else {
        printf("[ Function ] CSV Count ASCII Int Byte: Open CSV Successful.\n");

        while ((ch_ascii = getc(fp)) != EOF) num++;
    }
    fclose(fp);

    printf("[ Function ] CSV Count ASCII Int Byte: Finished, Have %d ASCII Int Byte.\n", num);
    return num;

}