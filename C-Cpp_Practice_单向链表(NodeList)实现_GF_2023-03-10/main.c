//
// Created by GF on 2023/3/10.
//

#include <stdio.h>
#include "NodeList_Function.h"

int main() {

    struct Node* Head = NodeListInit();

    printf("****************** Append Test *******************\n");

    NodeAppend(Head, "2023-03-11");
    NodeAppend(Head, "2023-03-12");
    NodeAppend(Head, "2023-03-13");
    NodeAppend(Head, "2023-03-14");
    NodeAppend(Head, "2023-03-15");

    NodeListPrint(Head);

    printf("****************** Insert Test *******************\n");

    NodeInsert(Head, "2023-03-16", 2);

    NodeListPrint(Head);

    printf("****************** Length Test *******************\n");

    printf("This NodeList Length: %d\n", NodeListLength(Head));

    printf("****************** FindSeq Test ******************\n");

    struct Node* FoundResult = NULL;
    FoundResult = NodeFindSeq(Head, 3);
    if (FoundResult != NULL) printf("In Seq.%d Found: %s\n", FoundResult->Seq, FoundResult->Date);

    printf("******************* Free Test ********************\n");

    NodeListFree(Head);
    NodeListPrint(Head);

    return 0;
}
