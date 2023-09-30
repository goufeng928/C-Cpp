//
// Created by GF on 2023/3/10.
//

#ifndef NODELIST_FUNCTION_H
#define NODELIST_FUNCTION_H

struct Node {

    int Seq;
    char Date[11];
    struct Node* Next;
};

//NodeList初始化。
struct Node* NodeListInit();

//NodeList输出。
void NodeListPrint(struct Node* Head);

//NodeList长度。
int NodeListLength(struct Node* Head);

//NodeList按序号查找节点。
struct Node* NodeFindSeq(struct Node* Head, int Seq);

//NodeList末尾添加节点。
void NodeAppend(struct Node* Head, char* Value);

//NodeList在指定序号的节点后面插入节点并赋值。
void NodeInsert(struct Node* Head, char* Value, int FrontSeq);

//NodeList清空。
void NodeListFree(struct Node* Head);

#endif //NODELIST_FUNCTION_H
