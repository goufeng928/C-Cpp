//
// Created by GF on 2023/2/21.
//

#include <stdio.h>
#include <time.h>

//用mktime读取日期生成时间戳(原始版本: 年月日3个整数参数传入)。
int time_stamp_use_int_by_mktime(int Year, int Month, int Day) {

    //创建并初始化time_t类型数据。
    time_t res_sec = 0;

    struct tm p;
    p.tm_year = Year-1900;
    p.tm_mon = Month-1;
    p.tm_mday = Day;
    p.tm_hour = 0;
    p.tm_min = 0;
    p.tm_sec = 0;
    p.tm_isdst = 0;

    res_sec = mktime(&p);

    //time(&res_sec)函数将现在的时间转换成秒并保存在res_sec变量中。
    //time(&res_sec);

    return res_sec;

}