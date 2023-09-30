//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//用getc清洗CSV文件个别字符。
void wash_csv_by_getc(char* source_csv) {

    FILE *fp1, *fp2;
    int ch_ascii;

    //CSV文件需要转换成GBK或GB2312编码，否则中文输出为乱码。
    fp1 = fopen(source_csv, "r");
    fp2 = fopen("./washed_csv.csv", "w");

    if (fp1 == NULL) {
        printf("[ Function ] Wash CSV: Open CSV Failed.\n");
    }
    else {
        printf("[ Function ] Wash CSV: Open CSV Successful.\n");

        while ((ch_ascii = getc(fp1)) != EOF) {
            //ASCII码中，32为SPACE(空格)，34为"(英文双引号)，39为'(英文单引号)。
            if (ch_ascii != 32 && ch_ascii != 34 && ch_ascii != 39) putc(ch_ascii, fp2);
        }

        printf("[ Function ] Wash CSV: Wash CSV Finished.\n");
    }

    fclose(fp1);
    fclose(fp2);

}