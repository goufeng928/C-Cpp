//
// Created by GF on 2023/3/10.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "NodeList_Function.h"

//NodeList初始化。
struct Node* NodeListInit() {

    struct Node* Head = (struct Node*)malloc(sizeof(struct Node));
    memset(Head, 0, sizeof(*Head));
    Head->Next = NULL;

    return Head;
}

//NodeList输出。
void NodeListPrint(struct Node* Head) {

    if (Head->Next == NULL) {

        printf("[ NodeList Error ] NodeListPrint: NodeList is Empty.\n");

    } else if (Head->Next != NULL) {

        struct Node* Show = Head;

        while (Show->Next != NULL) {

            Show = Show->Next; //因为尾结点的next为空，e为了可输出其值，这样巧妙使其可被输出。

            printf("Seq.%d: %s\n", Show->Seq, Show->Date);
        }
    }
}

//NodeList长度。
int NodeListLength(struct Node* Head) {

    if (Head->Next == NULL) {

        return 0;

    } else if (Head->Next != NULL) {

        int Length = 0;

        struct Node* CountLen = Head;

        while (CountLen->Next != NULL) {

            CountLen = CountLen->Next; //因为尾结点的next为空，e为了可输出其值，这样巧妙使其可被输出。

            Length++;
        }

        return Length;
    }
}

//NodeList按序号查找节点。
struct Node* NodeFindSeq(struct Node* Head, int Seq) {

    if (Head->Next == NULL) {

        return NULL;

    } else if (Head->Next != NULL) {

        struct Node* CopyFind = Head;

        //While循环：开始。
        while (CopyFind->Next != NULL) {

            CopyFind = CopyFind->Next;

            //条件判断：开始。
            if(CopyFind->Seq == Seq) {

                return CopyFind;
            }
            //条件判断：结束。
        }
        //While循环：结束。
    }

    return NULL; //如果没有找到相应的值。
}

//NodeList末尾添加节点。
void NodeAppend(struct Node* Head, char* Value) {

    if (Head->Next == NULL) {

        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));

        NewNode->Seq = 0; //分配序号。
        strcpy(NewNode->Date, Value); //赋值。

        NewNode->Next = NULL;

        Head->Next = NewNode;

    } else if (Head->Next != NULL) {

        struct Node* LastNode;

        LastNode = Head;
        while (LastNode->Next != NULL) LastNode = LastNode->Next;

        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));

        LastNode->Next = NewNode;

        NewNode->Seq = LastNode->Seq + 1; //分配序号。
        strcpy(NewNode->Date, Value); //赋值。

        NewNode->Next = NULL;
    }
}

//NodeList在指定序号的节点后面插入节点并赋值。
void NodeInsert(struct Node* Head, char* Value, int FrontSeq) {

    int Len = NodeListLength(Head);

    if (FrontSeq >= Len) {

        NodeAppend(Head, Value);

        printf("[ NodeList Error ] NodeInsert: FrontSeq Exceeds The Length, Appended to The End.\n");

    } else if (FrontSeq < Len) {

        struct Node* Found = NodeFindSeq(Head, FrontSeq);

        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));

        NewNode->Next = Found->Next; //将插入的新节点的Next指向原位置节点的Next的值。

        Found->Next = NewNode; //将原位置节点的Next指向新节点。

        NewNode->Seq = Found->Seq + 1; //分配序号。
        strcpy(NewNode->Date, Value); //赋值。

        /* ******************** Separate ******************** */
        //为插入的新节点后面的节点重新分配序号。
        struct Node* Following = NewNode;

        while (Following->Next != NULL) {

            Following = Following->Next; //NodeList默认是跳过头节点的，这里Following就相当于头节点。

            Following->Seq += 1;
        }
    }
}

//NodeList清空。
void NodeListFree(struct Node* Head) {

    if (Head->Next == NULL) {

        printf("[ NodeList Error ] NodeListFree: NodeList is Empty.\n");

    } else if (Head->Next != NULL) {

        //一个一个NULL。
        struct Node* CopyErgodic = Head; //定义一个临时变量来指向头。

        while (CopyErgodic != NULL) {

            struct Node* Trash = CopyErgodic;

            CopyErgodic = CopyErgodic->Next; //Temp指向下一个的地址，即实现++操作。

            free(Trash); //释放选定的节点。
        }
        //头重新赋值NULL，不然下次的头就接着0x10。
        Head->Next = NULL;
    }
}
