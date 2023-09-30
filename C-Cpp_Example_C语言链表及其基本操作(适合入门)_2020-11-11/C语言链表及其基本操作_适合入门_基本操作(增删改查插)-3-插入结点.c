void addnod(struct nod * head,int a)
{
	if(head == NULL)
		return ;
		
	struct  nod * temp  = Findnod(head,a);
	
	struct  nod * newnod = (struct  nod *)malloc(sizeof(struct  nod ));
	
	scanf("%d",&newnod->date);
	
	newnod->next = temp->next;
	temp->next = newnod;
	
	return ;
} 
