#include <stdio.h>

//利用getchar()和putchar()按顺序连续读取字符并回显。
int sequence_read_char(void){
    /*
     * getchar()和putchar()是stdio.h中的库函数。
     * 在C语言中，getchar代表读入一个字符，putchar代表输出一个字符。
     * getchar从stdin流中读取一个字符并返回。
     * getchar有一个int型的返回值，当程序调用getchar时，程序就等着用户按键。
     * 用户输入的字符被存放在键盘缓冲区中，直到用户按回车为止(回车字符也放在缓冲区中)。
     */

    //ch之前定义最好用int。
    //因为通过查函数发现它返回的是一个int型。
    //所以在创建类型的时候就创建int防止后面产生EOF导致程序退出。
    int ch_ascii;

    //文件结束符EOF全称End Of File。
    //Windows下为组合键Ctrl+Z。
    //Unix和Linux下为组合键Ctrl+D。
    while ((ch_ascii = getchar()) != EOF){

        //putchar作用是向终端输出一个字符。其格式为putchar(ch)。
        //其中ch可以是被单引号(英文状态下)引起来的一个字符，可以是介于0~127之间的一个十进制整型数。
        //也可以是事先用char定义好的一个字符型变量。。
        putchar(ch_ascii);

    }

}
