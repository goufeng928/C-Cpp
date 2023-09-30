//
// Created by GF on 2023/2/21.
//

#include <stdio.h>

//计数CSV文件内数据的行数。
int csv_count_number_of_rows(char* csv_path, int Option) {

    FILE *fp;
    int number_of_rows = 0;
    char row[500];

    fp = fopen(csv_path, "r");

    while (fgets(row, 500, fp)) number_of_rows += 1;

    printf("[ Function ] CSV Count Number Of Rows: Finished, Total Rows: %d.\n", number_of_rows);

    //设定Option选项，如果Option的值为1，则行数包含表头，如果Option的值为0，则行数不包含表头。
    if (Option == 1) return number_of_rows;
    else if (Option == 0) return number_of_rows - 1;

}