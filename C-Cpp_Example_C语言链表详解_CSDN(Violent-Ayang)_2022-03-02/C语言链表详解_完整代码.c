#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;//数据域 
	struct Node* next;//指针域 
};
//创建链表 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode 成为了结构体变量
	//变量使用前必须被初始化
	headNode->data = 1;
	headNode->next = NULL;
	return headNode; 
}
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void printList(struct Node* headNode){
	struct Node* pMove = headNode->next;
	while(pMove){
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//插入结点 
void insertNodeByHead(struct Node* headNode,int data){
	//1.创建插入的结点
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode; 
}
void deleteNodeByAppoin(struct Node* headNode,int posData){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if(!posNode){
		printf("链表为空，无法删除链表");
	}
	while(posNode->data!=posData){
		posNodeFront = posNode;
		posNode = posNode->next;
		if(!posNode){
			printf("没有找到要删除结点，无法删除");
			return;
		}
	}
	posNodeFront->next = posNode->next;
	free(posNode);
}
int main()
{
    struct Node* list = createList();
	insertNodeByHead(list,1); 
	insertNodeByHead(list,2); 
	insertNodeByHead(list,3); 
	deleteNodeByAppoin(list,2);
	printList(list);
    return 0;
}

