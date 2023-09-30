void printList(struct Node* headNode){
	struct Node* pMove = headNode->next;
	while(pMove){
		printf("%d",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
