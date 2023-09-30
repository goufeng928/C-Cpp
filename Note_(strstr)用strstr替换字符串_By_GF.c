//
// Create By GF at 2023-03-04 15:22 
//

#include <stdio.h>
#include <string.h>

int main() {

    /* ******************** Case 1 ******************** */

    char* strA = "This is a simple string";
    char* pch;

    pch = strstr(starA, "a"); //返回第一次出现"a"的指针。

    if (pch != NULL) *pch = '1'; //将'a'替换赋值为'1'。

    printf("strA = %s\n",strA);

    /*
     * 输出：
     * This is 1 simple string
     */
    
    /* ******************** Case 2 ******************** */
    
    char* strA = "This is a simple string";
    char* pch;

    pch = strstr(starA, "simple"); //返回第一次出现"simple"的指针。

    strncpy (pch, "sample", 6);

    printf("strA = %s\n",strA);

    /*
     * 输出：
     * This is a sample string
     */

    return 0;
}