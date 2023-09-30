//
// Create By GF at 2023-03-04 15:22 
//

#include <stdio.h>
#include <string.h>

int main() {

    char ch1[] = "abcdef";
	char ch2[] = "abz";

	int result = strcmp(ch1, ch2);

	printf("%d\n", result);

    /*
     * 比较规则：
     * 对两个字符串从左向右逐个字符比较ASCll码大小。
     * 直到遇到不同字符或“\0”为止。
     * 例如上述代码 ch1 和 ch2，前两个字符 a, b 是相等的，第三个字符 z 是大于 c 的。
     * 所以 ch2 是大于 ch1 的。
     */

    /*
     * 返回值：
     * 返回int型整数。
     * a.若字符串1 <  字符串2，返回负整数
     * b.若字符串1 >  字符串2，返回正整数
     * c.若字符串1 == 字符串2，返回零
     * 例如上述代码的返回值是-1，小于0。
     */

    return 0;
}