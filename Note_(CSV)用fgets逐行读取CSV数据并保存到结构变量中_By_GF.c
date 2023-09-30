//
// Created by GF on 2023/2/22.
//

#include <stdio.h>

//用fgets逐行读取CSV数据并保存到结构变量中。
void read_csv_to_struct_by_fgets(struct finance_data* ptr_stu, int rows_num) {

    FILE *fp;
    char row[200], trash[200];
    char ch_date[11], ch_name[13], ch_code[8], ch_open[13], ch_high[13],
         ch_low[13], ch_close[13], ch_pre_close[13], ch_volume[13];

    //CSV文件需要转换成GBK编码，否则中文输出为乱码。
    fp = fopen("./csv_pretreated/csv_pretreated.csv", "r");

    if (fp == NULL) {
        printf("[ Function ] Read CSV To Struct: Open CSV Failed.\n");
    }else {
        printf("[ Function ] Read CSV To Struct: Open CSV Successful.\n");

        //利用fgets的特性，读到换行符后文件指针自动下移，以便于跳过表头。
        fgets(trash, 200, fp);

        char match_string[] = "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]";

        for (int i = 0; i < rows_num; i++) {
            fgets(row, 200, fp);

            sscanf(row, match_string,
                   ch_date, ch_name, ch_code, ch_open, ch_high,
                   ch_low, ch_close, ch_pre_close, ch_volume);

            strcpy(ptr_stu->date,ch_date);
            strcpy(ptr_stu->name,ch_name);
            strcpy(ptr_stu->code,ch_code);

            ptr_stu->open = atof(ch_open);
            ptr_stu->high = atof(ch_high);
            ptr_stu->low = atof(ch_low);
            ptr_stu->close = atof(ch_close);
            ptr_stu->pre_close = atof(ch_pre_close);
            ptr_stu->volume = atof(ch_volume);

            //fgets读取CSV数据并保存到结构变量中: 函数内部调试。
            printf("%s | %s | %s | %.4f | %.4f | %.4f | %.4f | %.4f | %.4f\n",
                   ptr_stu->date, ptr_stu->name, ptr_stu->code, ptr_stu->open, ptr_stu->high,
                   ptr_stu->low, ptr_stu->close, ptr_stu->pre_close, ptr_stu->volume);

            ptr_stu += 1;
        }
        printf("[ Function ] Read CSV To Struct: Finished.\n");

    }
    fclose(fp);

}