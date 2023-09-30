/*
 * main.c
 *
 * Created by GF on 2023/3/10.
 */

#include <stdio.h>
#include "Matrix_NodeList.h"

int main() {

    /*
     * Test Data:
     *
     *     |1, 8,  11  |
     *     |1, 9,  8.5 |
     * X = |1, 11, 15  |
     *     |1, 16, 18  |
     *     |1, 12, 11  |
     */

    struct Matrix_Node* Matrix_Head = Matrix_NodeList_Init();

    Matrix_NodeList_Append(Matrix_Head, 1, 1, 1);
    Matrix_NodeList_Append(Matrix_Head, 1, 2, 8);
    Matrix_NodeList_Append(Matrix_Head, 1, 3, 11);
    Matrix_NodeList_Append(Matrix_Head, 2, 1, 1);
    Matrix_NodeList_Append(Matrix_Head, 2, 2, 9);
    Matrix_NodeList_Append(Matrix_Head, 2, 3, 8.5);
    Matrix_NodeList_Append(Matrix_Head, 3, 1, 1);
    Matrix_NodeList_Append(Matrix_Head, 3, 2, 11);
    Matrix_NodeList_Append(Matrix_Head, 3, 3, 15);
    Matrix_NodeList_Append(Matrix_Head, 4, 1, 1);
    Matrix_NodeList_Append(Matrix_Head, 4, 2, 16);
    Matrix_NodeList_Append(Matrix_Head, 4, 3, 18);
    Matrix_NodeList_Append(Matrix_Head, 5, 1, 1);
    Matrix_NodeList_Append(Matrix_Head, 5, 2, 12);
    Matrix_NodeList_Append(Matrix_Head, 5, 3, 11);

    printf("Original Matrix :\n");
    Matrix_NodeList_Format_Print(Matrix_Head);

    printf("Delete Test :\n");

    Matrix_NodeList_Delete_Row_By_Index(Matrix_Head, 5, 1);
    Matrix_NodeList_Delete_Col_By_Index(Matrix_Head, 1, 1);

    Matrix_NodeList_Format_Print(Matrix_Head);

    //printf("Max Number of Rows : %d\n",Matrix_NodeList_Max_Rows_Num(Matrix_Head));
    //printf("Max Number of Cols : %d\n",Matrix_NodeList_Max_Cols_Num(Matrix_Head));

    //printf("Finded Row : 2, Col : 2, Value : %f\n", Matrix_NodeList_Find_Value_By_Index(Matrix_Head, 2, 2));

    return 0;
}
