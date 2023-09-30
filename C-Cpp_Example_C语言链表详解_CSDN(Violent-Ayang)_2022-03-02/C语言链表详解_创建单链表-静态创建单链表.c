#include<stdio.h>

struct Node{
	int data;//数据域 
	struct Node* next;//指针域 
}; 
 
int main()
{
    struct Node node1 = {1,NULL}; 
    struct Node node2 = {2,NULL}; 
    struct Node node3 = {3,NULL}; 
    node1.next = &node2;
    node2.next = &node3;
    return 0;
}

