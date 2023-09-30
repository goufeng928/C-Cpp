#include <stdio.h>
#include "mysql.h"

/*
 *
主要用到的函数:
    mysql_library_init
    mysql_init 初始化
    mysql_real_connect 连接服务器
    mysql_query和mysql_real_query 执行sql语句，区别请参考官网
    mysql_use_result 启用结果集，按行数据进行迭代，猜测内部结果是个链表
    mysql_store_result 将结果数据全部放入内存中，如果数据量超大会出问题
    mysql_fetch_row 获取一行数据(是个二级字符指针)
    mysql_num_fields 获取查询结果的字段数据
    mysql_free_result 释放结果集所分配的内存
    mysql_close 关闭连接
    mysql_library_end
 */
int main() {
    // step 1 通过调用初始化 MySQL 客户端库 mysql_library_init()。
    if (mysql_library_init(0, NULL, NULL)) {
        fprintf(stderr, "could not initialize MySQL client library\n");
        exit(-1);
    }
    // step2 通过调用初始化连接处理程序 mysql_init()并通过调用连接到服务器 mysql_real_connect()。
    // MYSQL * mysql_init(MYSQL *mysql);
    MYSQL *conn = mysql_init(NULL);
    // 创建失败,官网说内存不足导致的(具体情况的话，还要看源码逻辑)
    if (conn == NULL) {
        fprintf(stderr, "create mysql connecting failed\n ");
    }
    // 连接mysql
    // 如果MYSQL*连接成功，则连接处理程序，NULL如果连接不成功。对于成功的连接，返回值与第一个参数的值相同。
    conn = mysql_real_connect(conn, "localhost", "root", "123456", "sugartest", 3306, NULL, 0);
    if (conn == NULL) {
        fprintf(stderr, "连接mysql服务器失败\n ");
        exit(-1);
    }
    //设置查询编码为 utf8, 支持中文
    // 如果不设置，后面查询的数据含有中文会出现乱码
    mysql_query(conn, "set names utf8");
    // 操作
    // 执行的sql语句编写
    char *execSql = "select * from tbl_author";
    // 执行sql
    // 自动提交
//    mysql_autocommit(conn, 1);
    mysql_real_query(conn, execSql, strlen(execSql));
    // 获取结果集
    // mysql_use_result()  启动逐行结果集检索
    MYSQL_RES *rs = mysql_use_result(conn);
//     将结果全部缓存到内存中
//    MYSQL_RES *rs = mysql_store_result(conn);
    // 判断是否有结果集
    if (rs) {
        // mysql_num_rows()    结果集中的行数
        // 在使用mysql_use_result获取结果集的时候，始终为0，原因是由于是按行数返回的
//        my_ulonglong totalRows = mysql_num_rows(rs);
//        fprintf(stdout, "总记录数:%llu\n", totalRows);
        // 二级指针
        MYSQL_ROW row;
        while ((row = mysql_fetch_row(rs))) {
//            mysql_num_fields()   结果集中的列数即字段
            for (int i = 0; i < mysql_num_fields(rs); ++i) {
                printf("%s ",row[i]);
            }
            printf("\n");
        }
    }
    // 释放结果集占用的内存
    mysql_free_result(rs);
    // 关闭conn
    mysql_close(conn);
    // 通过调用结束 MySQL 客户端库的使用 mysql_library_end()。
    mysql_library_end();
    return 0;
}
