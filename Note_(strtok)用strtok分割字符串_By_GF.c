//
// Create By GF at 2023-02-23 17:57 
//

#include <stdio.h>
#include <string.h>

int main() {

    char* Str_Test = "Name,Date,Code,Open,High,Low,Close,Pre Close,Volume";
    char* Ptr_Str;//字符指针。
    char Row[100];

    const char* delim = ",";

    //字符指针转给字符常量，否则不能用strtok，因为strtok是靠替换分割字符为\0来实现。
    strcpy(Row, Str_Test);

    printf("Str_Test = %s\n", Str_Test);

    int i = 0;

    Ptr_Str = strtok(Row, delim);

    while (Ptr_Str != NULL && i < 9) {//以9个待分割字符串为例。

	    printf("No.%d: %s\n",i, Ptr_Str);

	    Ptr_Str = strtok(NULL, delim);

	    i++;
    }

    return 0;
}