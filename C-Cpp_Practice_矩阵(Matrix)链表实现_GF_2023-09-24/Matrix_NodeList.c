/*
 * Matrix_Nodelist.c
 *
 * Created by GF on 2023/3/10.
 */

#include <stdio.h>  /* printf() */
#include <string.h> /* memset(); memcpy(); */
#include <malloc.h> /* malloc() */
#include "Matrix_NodeList.h"

/* Matrix NodeList 初始化 */
struct Matrix_Node* Matrix_NodeList_Init() {

    /* 创建一个矩阵链表的表头表示整个矩阵链表 */
    struct Matrix_Node* Matrix_NodeList_Head = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));

    /* memset 函数按字节对内存块进行初始化 */
    memset(Matrix_NodeList_Head, 0, sizeof(*Matrix_NodeList_Head));

    /* 将 Martrix NodeList 的 Next 设置为 NULL */
    Matrix_NodeList_Head->Next = NULL;

    return Matrix_NodeList_Head;
}

/* Matrix NodeList 最大行数 */
int Matrix_NodeList_Max_Rows_Num(struct Matrix_Node* Matrix_Head) {

    if (Matrix_Head->Next == NULL) { /* 条件判断 : 如果矩阵链表指向的 Next 节点为 NULL */

        return 0;

    } else if (Matrix_Head->Next != NULL) {

        int Rows_Counted = 0;

        struct Matrix_Node* Temp = Matrix_Head; /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */

        while (Temp->Next != NULL) {

            int Current_Row_Index = Temp->Row_Index;

            Temp = Temp->Next; /* 因为尾结点的 Next为空, 为了可输出其值, 把节点赋值放在前面使其可被输出 */

            if (Current_Row_Index > Rows_Counted) { /* 条件判断 : 如果当前矩阵链表保存的行号大于 Rows_Counted 变量 */

                Rows_Counted = Current_Row_Index;
            }
        }

        return Rows_Counted;
    }
}

/* Matrix NodeList 最大列数 */
int Matrix_NodeList_Max_Cols_Num(struct Matrix_Node* Matrix_Head) {

    if (Matrix_Head->Next == NULL) { /* 条件判断 : 如果矩阵链表指向的 Next 节点为 NULL */

        return 0;

    } else if (Matrix_Head->Next != NULL) {

        int Cols_Counted = 0;

        struct Matrix_Node* Temp = Matrix_Head; /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */

        while (Temp->Next != NULL) {

            int Current_Col_Index = Temp->Col_Index;

            Temp = Temp->Next; /* 因为尾结点的 Next为空, 为了可输出其值, 把节点赋值放在前面使其可被输出 */

            if (Current_Col_Index > Cols_Counted) { /* 条件判断 : 如果当前矩阵链表保存的行号大于 Cols_Counted 变量 */

                Cols_Counted = Current_Col_Index;
            }
        }

        return Cols_Counted;
    }
}

/* Matrix NodeList 按 Index 查找 Value */
double Matrix_NodeList_Find_Value_By_Index(struct Matrix_Node* Matrix_Head, int Row_Index, int Col_Index) {

    if (Matrix_Head->Next == NULL) { /* 条件判断 : 如果矩阵链表指向的 Next 节点为 NULL */

        return 0;

    } else if (Matrix_Head->Next != NULL) {

        double Res = 0.0;

        /* ************************************ */

        struct Matrix_Node* Temp = Matrix_Head; /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */

        while (Temp->Next != NULL) {

            Temp = Temp->Next;

            /* ******************************** */

            /* 条件判断 : 如果当前矩阵链表行索引等于传入索引并且列索引等于传入索引 */
            if (Temp->Row_Index ==  Row_Index && Temp->Col_Index == Col_Index) {
                Res =  Temp->Value;
                break;
            }
        }
        return Res;
    }
}

/* Matrix NodeList 格式化输出 */
void Matrix_NodeList_Format_Print(struct Matrix_Node* Matrix_Head) {

    /* 条件判断 : 如果矩阵链表指向的 Next 节点为 NULL */
    if (Matrix_Head->Next == NULL) {

        printf("Matrix NodeList Notice : Matrix NodeList is Empty, Format Print Failed.\n");

    } else if (Matrix_Head->Next != NULL) {

        int Max_Rows_Num = Matrix_NodeList_Max_Rows_Num(Matrix_Head);
        int Max_Cols_Num = Matrix_NodeList_Max_Cols_Num(Matrix_Head);

        /* ************************************ */

        for (int i = 1; i <= Max_Rows_Num; i++){

            struct Matrix_Node* Show = Matrix_Head;

            for (int j = 1; j <= Max_Cols_Num; j++){

                printf("%f ", Matrix_NodeList_Find_Value_By_Index(Show, i, j));
            }
            printf("\n");
        }
    }
}

/* Matrix NodeList 末尾添加节点 */
void Matrix_NodeList_Append(struct Matrix_Node* Matrix_Head, int Row_Index, int Col_Index, double Value) {

    if (Matrix_Head->Next == NULL) {

        struct Matrix_Node* New = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));

        New->Row_Index = Row_Index; /* 行索引赋值 */
        New->Col_Index = Col_Index; /* 列索引赋值 */
        New->Value = Value; /* 数据赋值 */

        New->Next = NULL; /* 将 Matrix Nodelist 新节点的 Next 赋值为 NULL 作为尾节点 */

        Matrix_Head->Next = New; /* 将 Matrix Nodelist 头节点的 Next 赋值为新节点 */

    } else if (Matrix_Head->Next != NULL) {

        struct Matrix_Node* End;

        End = Matrix_Head;
        while (End->Next != NULL) End = End->Next;

        struct Matrix_Node* New = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));

        End->Next = New;

        New->Row_Index = Row_Index; /* 行索引赋值 */
        New->Col_Index = Col_Index; /* 列索引赋值 */
        New->Value = Value; /* 数据赋值 */

        New->Next = NULL;
    }
}

/* Matrix NodeList 矩阵链表完整复制 */
struct Matrix_Node* Matrix_NodeList_Full_Copy(struct Matrix_Node* Matrix_Head_Source) {

    /* 条件判断 : 如果 Source 矩阵链表头指向的 Next 节点为 NULL */
    if (Matrix_Head_Source->Next == NULL) {

        printf("Matrix NodeList Notice : Matrix NodeList is Empty, Full Copy Failed.\n");

    } else {

        /* 创建一个矩阵链表的表头用于接收被复制(Copy)的矩阵链表 */
        struct Matrix_Node* Matrix_Head_Dist = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));
        
        /* ************************************ */
        
        /* 将目标矩阵链表 Head 节点赋值到 Dist 以防原链表被循环更改 */
        struct Matrix_Node* Dist = Matrix_Head_Dist;
        /* 将原始矩阵链表 Head 节点赋值到 Temp 以防原链表被循环更改 */
        struct Matrix_Node* Temp = Matrix_Head_Source;
        
        /* ************************************ */
        
        /* memcpy 复制矩阵链表 Head 数据 (不进行此操作将会出问题 / 原因未知) */
        memcpy(Matrix_Head_Dist, Temp, sizeof(*Temp));
        
        /* ************************************ */
        
        while (Temp->Next != NULL) {
            
            /* 让 Temp 等于 Next 指向的节点 (有数据的节点) */
            Temp = Temp->Next;
            
            /* 创建新的矩阵链表节点并用于接收复制的 Node 数据 */
            struct Matrix_Node* New_Node = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));
            
            /* memcpy 复制矩阵链表 Node 数据 */
            memcpy(New_Node, Temp, sizeof(*Temp));
            
            Dist->Next = New_Node;
            
            Dist = Dist->Next;
        }
        
        free(Dist);
        
        free(Temp);
        
        return Matrix_Head_Dist;
    }
}

/* Matrix NodeList 按 Index 删除行 */
void Matrix_NodeList_Delete_Row_By_Index(struct Matrix_Node* Matrix_Head, int Row_Index, int Reindex){
    
    /*
     * Function Name : Matrix NodeList Delete Row By Index
     *
     * Matrix_NodeList_Delete_Row_By_Index(struct Matrix_Node* Matrix_Head, int Row_Index, int Reindex);
     *
     * Matrix_Head : Structure Pointer of Matrix_NodeList | Type : struct Matrix_Node*
     * Row_Index : Index of Row to Delete | Type : int
     * Reindex : Do You Want to Reset The Index (1 or 0) | Type : int
     */

    /* 条件判断 : 如果矩阵链表头指向的 Next 节点为 NULL */
    if (Matrix_Head->Next == NULL) {

        printf("Matrix NodeList Notice : Matrix NodeList is Empty, Delete Row Failed.\n");

    } else if (Matrix_Head->Next != NULL) {

        /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */
        struct Matrix_Node* Temp = Matrix_Head;

        while (Temp->Next != NULL) {

            struct Matrix_Node* Previous = Temp;

            struct Matrix_Node* Current = Previous->Next;

            /* ******************************** */

            /* 条件判断 : 如果当前矩阵链表行索引等于传入索引 */
            if (Current->Row_Index == Row_Index && Current->Next != NULL) {
                /* Previous 节点直接指向 Current 的下1个节点 */
                Previous->Next = Current->Next;
                /* 释放 Current 节点 */
                free(Current);
                /* 删除 Current 后 Previous-Next 成了新的节点, 要使这个值也被条件判断, 应跳过本次 Temp = Temp->Next */
                continue;
            } else if (Current->Row_Index == Row_Index && Current->Next == NULL) {
                /* Previous 节点直接指向 NULL */
                Previous->Next = NULL;
                /* 释放 Current 节点 */
                free(Current);
                /* 停止循环 */
                break;
            }

            Temp = Temp->Next;
        }
        
        /* Reindex = 1 则重置行索引 */
        if (Reindex = 1) {
            /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */
            struct Matrix_Node* Temp = Matrix_Head;

            while (Temp->Next != NULL) {
                
                Temp = Temp->Next;
                /* 条件判断 : 如果当前矩阵链表行索引大于传入索引 */
                if (Temp->Row_Index > Row_Index) {
                    /* 将当前矩阵链表的行索引 - 1 */
                    Temp->Row_Index = Temp->Row_Index - 1;
                }
            }
        }
    }
}

/* Matrix NodeList 按 Index 删除列 */
void Matrix_NodeList_Delete_Col_By_Index(struct Matrix_Node* Matrix_Head, int Col_Index, int Reindex){
    
    /*
     * Function Name : Matrix NodeList Delete Col By Index
     *
     * Matrix_NodeList_Delete_Col_By_Index(struct Matrix_Node* Matrix_Head, int Col_Index, int Reindex);
     *
     * Matrix_Head : Structure Pointer of Matrix_NodeList | Type : struct Matrix_Node*
     * Col_Index : Index of Col to Delete | Type : int
     * Reindex : Do You Want to Reset The Index (1 or 0) | Type : int
     */

    /* 条件判断 : 如果矩阵链表头指向的 Next 节点为 NULL */
    if (Matrix_Head->Next == NULL) {

        printf("Matrix NodeList Notice : Matrix NodeList is Empty, Delete Col Failed.\n");

    } else if (Matrix_Head->Next != NULL) {

        /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */
        struct Matrix_Node* Temp = Matrix_Head;

        while (Temp->Next != NULL) {

            struct Matrix_Node* Previous = Temp;

            struct Matrix_Node* Current = Previous->Next;

            /* ******************************** */

            /* 条件判断 : 如果当前矩阵链表列索引等于传入索引 */
            if (Current->Col_Index == Col_Index && Current->Next != NULL) {
                /* Previous 节点直接指向 Current 的下1个节点 */
                Previous->Next = Current->Next;
                /* 释放 Current 节点 */
                free(Current);
                /* 删除 Current 后 Previous-Next 成了新的节点, 要使这个值也被条件判断, 应跳过本次 Temp = Temp->Next */
                continue;
            } else if (Current->Col_Index == Col_Index && Current->Next == NULL) {
                /* Previous 节点直接指向 NULL */
                Previous->Next = NULL;
                /* 释放 Current 节点 */
                free(Current);
                /* 停止循环 */
                break;
            }

            Temp = Temp->Next;
        }
        
        /* Reindex = 1 则重置列索引 */
        if (Reindex = 1) {
            /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */
            struct Matrix_Node* Temp = Matrix_Head;

            while (Temp->Next != NULL) {
                
                Temp = Temp->Next;
                /* 条件判断 : 如果当前矩阵链表列索引大于传入索引 */
                if (Temp->Col_Index > Col_Index) {
                    /* 将当前矩阵链表的列索引 - 1 */
                    Temp->Col_Index = Temp->Col_Index - 1;
                }
            }
        }
    }
}

/* Matrix NodeList 清空所有节点 */
void Matrix_NodeList_Free(struct Matrix_Node* Matrix_Head) {

    if (Matrix_Head->Next == NULL) {

        printf("Matrix NodeList Notice : Matrix NodeList is Empty, Free Failed.\n");

    } else {

        //一个一个NULL。
        struct Matrix_Node* CopyErgodic = Matrix_Head; //定义一个临时变量来指向头。

        while (CopyErgodic != NULL) {

            struct Matrix_Node* Trash = CopyErgodic;

            CopyErgodic = CopyErgodic->Next; //Temp指向下一个的地址，即实现++操作。

            free(Trash); //释放选定的节点。
        }
        //头重新赋值NULL，不然下次的头就接着0x10。
        Matrix_Head->Next = NULL;
    }
}

/* 行列式(Determinant) NodeList 查找余子式 */
struct Matrix_Node* Determinant_NodeList_Find_Cofactor(struct Matrix_Node* Determinant_Head, int Row_Index, int Col_Index) {

    /* 条件判断 : 如果矩阵链表头指向的 Next 节点为 NULL */
    if (Determinant_Head->Next == NULL) {

        printf("Matrix NodeList Notice : Determinant NodeList is Empty, Find Cofactor Failed.\n");

    /* 条件判断 : 如果矩阵链表头指向的 Next 节点不为 NULL 并且第1个节点指向的 Next 节点为 NULL (行列式为1行1列) */
    } else if (Determinant_Head->Next != NULL && Determinant_Head->Next->Next == NULL) {

        return Determinant_Head;

    } else {

        /* 将 Head 节点赋值到 Temp 以防原链表被循环更改 */
        struct Matrix_Node* Temp = Determinant_Head;

        /* 完整复制行列式(Determinant)原链表到 Cofactor 以防原链表被更改 */
        struct Matrix_Node* Cofactor = Matrix_NodeList_Full_Copy(Temp);

        /* 调用其它函数 : Matrix NodeList 按 Index 删除行 */
        Matrix_NodeList_Delete_Row_By_Index(Cofactor, Row_Index, 1);

        /* 调用其它函数 : Matrix NodeList 按 Index 删除列 */
        Matrix_NodeList_Delete_Col_By_Index(Cofactor, Col_Index, 1);
        
        return Cofactor;
    }
}

/* 行列式(Determinant) NodeList 求值 - 递归降阶法 */
double Determinant_NodeList_Result_By_Recurrence_Reduced_Order(struct Matrix_Node* Determinant_Head, int Order) {
    
    /* 所有传入此函数的行列式(Determinant)都按第1行展开 */
    
    /* 返回值 */
    double Result = 0.0;
    
    /* **************************************** */
    
    if (Order > 3) {

        /* 当前行列式(Determinant)按将要消除的列进行迭代 */
        for (int Det_Col_Idx = 1; Det_Col_Idx <= Order; Det_Col_Idx++) {
            
            /* 将 Head 节点赋值到 Cofactor_Head 以防原链表被循环更改 */
            struct Matrix_Node* Cofactor_Head = Determinant_Head;

            /*
             * 遍历当前行列式(Determinant)的行索引和列索引.
             * 由于行列式(Determinant)按第1行展开, 查找余子式时, 行索引固定为 1 不变.
             */
            
            /* 调用其它函数 : 行列式(Determinant) NodeList 查找余子式 */
            Cofactor_Head = Determinant_NodeList_Find_Cofactor(Cofactor_Head, 1, Det_Col_Idx);

            /* ******************************** */
 
            /* 余子式正负号 : 初始取负 */
            int Plus_Minus = -1;
            
            /* 余子式正负号 : 若 行索引 + 列索引 为偶数, 则余子式取正 */
            if ((1 + Det_Col_Idx) % 2 == 0)
                Plus_Minus = 1;
            
            /* ******************************** */

            /* 调用其它函数 : Matrix NodeList 按 Index 查找 Value : 当前行列式(Determinant)首行 a1x 的值 */
            double a1x = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, Det_Col_Idx);

            /* 递归(Recurrence)调用 : 将当前余子式(Cofactor)当作行列式(Determinant)再次传入此函数 */
            Result += a1x * Plus_Minus * Determinant_NodeList_Result_By_Recurrence_Reduced_Order(Cofactor_Head, Order - 1);

            Matrix_NodeList_Free(Cofactor_Head);
        }
        
    /* 当行列式(Determinant)阶数小于3时直接用公式计算出结果 */
    } else {

        if (Order == 1) {
                Result = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 1);
        } else if (Order == 2) {
                double a11 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 1);
                double a12 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 2);
                double a21 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 2, 1);
                double a22 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 2, 2);
                Result = a11 * a22 - a12 * a21;
        } else if (Order == 3) {
                double a11 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 1);
                double a12 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 2);
                double a13 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 1, 3);
                double a21 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 2, 1);
                double a22 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 2, 2);
                double a23 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 2, 3);
                double a31 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 3, 1);
                double a32 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 3, 2);
                double a33 = Matrix_NodeList_Find_Value_By_Index(Determinant_Head, 3, 3);
                Result = (a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 -
                          a13 * a22 * a31 - a12 * a21 * a33 - a11 * a23 * a32);
        }
    }
    
    return Result;
}
