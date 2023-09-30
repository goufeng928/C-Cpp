void printlist(struct nod * head)
{
	if(head == NULL)
		return ;
	
	struct nod * p = head;
		
	while(p->next!=NULL)
	{		
			p = p->next;//因为尾结点的next为空，为了可输出其值，这样巧妙使其可被输出。
			printf("%d",p->date);
	
	}	
	
	return ;
}

