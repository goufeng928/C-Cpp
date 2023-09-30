/* Matrix_Test.c */

/* Create By GF 2023-09-28 00:35 */

/*
 * 5 8 9 4 5
 * 7 8 9 2 1
 * 3 2 1 4 5
 * 8 9 7 5 1
 * 1 2 4 5 7
 * 
 * 结果为 972
 */

/* Matrix NodeList 初始化 : 行列式链表头 */
struct Matrix_Node* Determinant_Head = (struct Matrix_Node*)malloc(sizeof(struct Matrix_Node));

/* Matrix NodeList 末尾添加节点 : 行列式添加值 */
Matrix_NodeList_Append(Determinant_Head, 1, 1, 5);
Matrix_NodeList_Append(Determinant_Head, 1, 2, 8);
Matrix_NodeList_Append(Determinant_Head, 1, 3, 9);
Matrix_NodeList_Append(Determinant_Head, 1, 4, 4);
Matrix_NodeList_Append(Determinant_Head, 1, 5, 5);
Matrix_NodeList_Append(Determinant_Head, 2, 1, 7);
Matrix_NodeList_Append(Determinant_Head, 2, 2, 8);
Matrix_NodeList_Append(Determinant_Head, 2, 3, 9);
Matrix_NodeList_Append(Determinant_Head, 2, 4, 2);
Matrix_NodeList_Append(Determinant_Head, 2, 5, 1);
Matrix_NodeList_Append(Determinant_Head, 3, 1, 3);
Matrix_NodeList_Append(Determinant_Head, 3, 2, 2);
Matrix_NodeList_Append(Determinant_Head, 3, 3, 1);
Matrix_NodeList_Append(Determinant_Head, 3, 4, 4);
Matrix_NodeList_Append(Determinant_Head, 3, 5, 5);
Matrix_NodeList_Append(Determinant_Head, 4, 1, 8);
Matrix_NodeList_Append(Determinant_Head, 4, 2, 9);
Matrix_NodeList_Append(Determinant_Head, 4, 3, 7);
Matrix_NodeList_Append(Determinant_Head, 4, 4, 5);
Matrix_NodeList_Append(Determinant_Head, 4, 5, 1);
Matrix_NodeList_Append(Determinant_Head, 5, 1, 1);
Matrix_NodeList_Append(Determinant_Head, 5, 2, 2);
Matrix_NodeList_Append(Determinant_Head, 5, 3, 4);
Matrix_NodeList_Append(Determinant_Head, 5, 4, 5);
Matrix_NodeList_Append(Determinant_Head, 5, 5, 7);

/* 测试 : Matrix NodeList 格式化输出 */
Matrix_NodeList_Format_Print(Determinant_Head);
printf("\n");

/* 行列式(Determinant) NodeList 求值 - 递归降阶法 */
printf("%f", Determinant_NodeList_Result_By_Recurrence_Reduced_Order(Determinant_Head, 5));
printf("\n");
