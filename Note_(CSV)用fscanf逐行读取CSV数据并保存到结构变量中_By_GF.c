//
// Created by GF on 2023/2/22.
//

#include <stdio.h>

//用fscanf逐行读取CSV数据并保存到结构变量中。
void read_csv_to_struct_by_fscanf(char *path, int rows_num, struct finance_data *pstu) {

    FILE *fp;
    char row[200], trash[200];
    char ch_date[11], ch_name[13], ch_code[8], ch_open[13],
         ch_high[13],ch_low[13], ch_close[13], ch_pre_close[13],
         ch_rise_fall[13],ch_rise_fall_rate[13], ch_turnover_rate[13], ch_volume[13];

    //CSV文件需要转换成GBK编码，否则中文输出为乱码。
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("[ Function ] Read CSV To Struct: Open CSV Failed.\n");
    }else {
        printf("[ Function ] Read CSV To Struct: Open CSV Successful.\n");

        //利用fgets的特性，读到换行符后文件指针自动下移，以便于跳过表头。
        fgets(trash, 200, fp);

        char match_string[] = " \"%[^,\"]\", \"%[^,\"]\", \"%[^,\"]\", "
                              " \"%[^,\"]\", \"%[^,\"]\", \"%[^,\"]\", "
                              " \"%[^,\"]\", \"%[^,\"]\", \"%[^,\"]\", "
                              " \"%[^,\"]\", \"%[^,\"]\", %[^\n] ";

        for (int i = 0; i < rows_num; i++) {
            fscanf(fp, "%s", row);

            sscanf(row, match_string,
                   ch_date, ch_name, ch_code, ch_open, ch_high,
                   ch_low, ch_close, ch_pre_close, ch_rise_fall, ch_rise_fall_rate,
                   ch_turnover_rate, ch_volume, trash);

            strcpy(pstu->date,ch_date);
            strcpy(pstu->name,ch_name);
            strcpy(pstu->code,ch_code);

            pstu->open = atof(ch_open);
            pstu->high = atof(ch_high);
            pstu->low = atof(ch_low);
            pstu->close = atof(ch_close);
            pstu->pre_close = atof(ch_pre_close);
            pstu->volume = atof(ch_volume);

            /*//fscanf读取CSV数据并保存到结构变量中: 函数内部调试。
            printf("%s | %s | %s | %.4f | %.4f | %.4f | %.4f | %.4f | %.4f\n",
                   pstu->name, pstu->name, pstu->code, pstu->open, pstu->high,
                   pstu->low, pstu->close, pstu->pre_close, pstu->volume);*/
            
            pstu += 1;
        }
        printf("[ Function ] Read CSV To Struct: Finished.\n");

    }
    fclose(fp);

}