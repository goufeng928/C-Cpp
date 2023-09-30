/*
 * Matrix_Nodelist.h
 *
 * Created by GF on 2023/3/10.
 */

#ifndef MATRIX_NODELIST_H
#define MATRIX_NODELIST_H

/* Matrix NodeList 节点 (Node) 结构 */ 
struct Matrix_Node {

    int Row_Index; /* Matrix 的行索引 */
    int Col_Index; /* Matrix 的列索引 */
    double Value; /* Matrix 的数据 */
    struct Matrix_Node* Next; /* Matrix Nodelist 的下一节点 */
};

/* Matrix NodeList 初始化 */
struct Matrix_Node* Matrix_NodeList_Init();

/* Matrix NodeList 最大行数 */
int Matrix_NodeList_Max_Rows_Num(struct Matrix_Node* Matrix_Head);

/* Matrix NodeList 最大列数 */
int Matrix_NodeList_Max_Cols_Num(struct Matrix_Node* Matrix_Head);

/* Matrix NodeList 按 Index 查找 Value */
double Matrix_NodeList_Find_Value_By_Index(struct Matrix_Node* Matrix_Head, int Row_Index, int Col_Index);

/* Matrix NodeList 格式化输出 */
void Matrix_NodeList_Format_Print(struct Matrix_Node* Matrix_Head);

/* Matrix NodeList 末尾添加节点 */
void Matrix_NodeList_Append(struct Matrix_Node* Matrix_Head, int Row_Index, int Col_Index, double Value);

/* Matrix NodeList 矩阵链表完整复制 */
struct Matrix_Node* Matrix_NodeList_Full_Copy(struct Matrix_Node* Matrix_Head_Source);

/* Matrix NodeList 按 Index 删除行 */
void Matrix_NodeList_Delete_Row_By_Index(struct Matrix_Node* Matrix_Head, int Row_Index, int Reindex);

/* Matrix NodeList 按 Index 删除列 */
void Matrix_NodeList_Delete_Col_By_Index(struct Matrix_Node* Matrix_Head, int Col_Index, int Reindex);

/* Matrix NodeList 清空所有节点 */
void Matrix_NodeList_Free(struct Matrix_Node* Matrix_Head);

/* 行列式(Determinant) NodeList 查找余子式 */
struct Matrix_Node* Determinant_NodeList_Find_Cofactor(struct Matrix_Node* Determinant_Head, int Row_Index, int Col_Index);

/* 行列式(Determinant) NodeList 求值 - 递归降阶法 */
double Determinant_NodeList_Result_By_Recurrence_Reduced_Order(struct Matrix_Node* Determinant_Head, int Order);

#endif //MATRIX_NODELIST_H
