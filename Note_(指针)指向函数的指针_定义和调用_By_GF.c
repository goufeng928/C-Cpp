//
// Create By GF at 2023-03-02 14:38 
//

#include <stdio.h>

int Add(int x, int y);

int main() {

	/*
	 * 数组名等于数组首元素地址，函数名等于函数地址。
	 * 但:
	 * 数组名(arr) != &数组名(&arr)。
     * 函数名(Add) == &函数名(&Add)。
	 *
	 * 故我们知道了对于：int Result = (*Ptr_Function)(3, 5); 语句来说，*是没有意义的，有一个或多个或者没有都不影响。
	 */

    //函数指针定义，返回值类型和参数类型与函数Add（）相同。
    int (*Ptr_Function)(int, int) = &Add;

    //int Result = (*Ptr_Function)(3, 5)，此时就相当于通过函数名调用。
	int Result = (*Ptr_Function)(3, 5);

    return 0;
}

int Add(int x, int y) {
	return x + y;
}