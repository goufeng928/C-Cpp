//
// Create By GF at 2023-03-02 14:15 
//

#include <stdio.h>

typedef struct
{
	int Member_0;
	int Member_1;
	int Member_2;
	int Member_3;
	int Member_4;
	int Member_5;
	int Member_6;
	int Member_7;
	int Member_8;
	int Member_9;
}Gather;

int main() {

    //结构体初始化赋值。
    Gather Stu = { 1,2,3,4,5,6,7,8,9,10 };

    //结构体成员变量的数量。
    int Member_Num = sizeof(Stu) / sizeof(int);
	
    //int类型的指针P指向结构体的第一个成员。
    int* P;
    P = &Stu.Member_0;
	
	for (int i = 0; i < Member_Num; i++) {
		printf("%d\n", *(P + i));
	}

    return 0;
}