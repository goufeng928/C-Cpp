//
// Created by GF on 2023/2/22.
//

#include <stdio.h>

//用getc逐字读取CSV文件内容并逐字输出。
void read_csv_by_getc(void) {

    FILE *fp;
    int ch_ascii;

    //CSV文件需要转换成GBK或GB2312编码，否则中文输出为乱码。
    fp = fopen("./000422.csv", "r");

    if (fp == NULL) {
        printf("[ Function ] Read CSV: Open CSV Failed.\n");
    }
    else {
        printf("[ Function ] Read CSV: Open CSV Successful.\n");

        while ((ch_ascii = getc(fp)) != EOF) putc(ch_ascii, stdout);

        printf("[ Function ] Read CSV: Finished.\n");
    }

    fclose(fp);

}