//插入结点 
void insertNodeByHead(struct Node* headNode,int data){
	//1.创建插入的结点
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode; 
}
