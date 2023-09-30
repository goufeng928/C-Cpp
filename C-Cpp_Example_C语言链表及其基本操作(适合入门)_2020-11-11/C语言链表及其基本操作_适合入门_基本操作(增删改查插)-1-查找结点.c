struct nod * Findnod(struct nod * head,int a)
{
	if(head == NULL)
		return NULL;
		
	struct nod * temp = head;	
		
	while(temp->next != NULL)
	{
		temp = temp->next;
		if(temp->date == a)
			return temp;
	} 
	
	return NULL;//没找到 
	
}
