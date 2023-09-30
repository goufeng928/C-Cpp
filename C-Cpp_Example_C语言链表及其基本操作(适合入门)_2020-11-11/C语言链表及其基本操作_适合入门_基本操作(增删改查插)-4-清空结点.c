void FreeList()
{
	//一个一个NULL
	struct Node *temp =head;		//定义一个临时变量来指向头
	while (temp !=NULL)
	{
	//	printf("%d\n",temp->a);
		struct Node* pt =temp;
		temp = temp->next;		//temp指向下一个的地址 即实现++操作
		free(pt);					//释放当前
	}
	//头尾清空	不然下次的头就接着0x10
	head =NULL;
	end =NULL;
}
