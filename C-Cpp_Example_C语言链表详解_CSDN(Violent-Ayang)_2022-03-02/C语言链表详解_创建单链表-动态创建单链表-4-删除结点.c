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
