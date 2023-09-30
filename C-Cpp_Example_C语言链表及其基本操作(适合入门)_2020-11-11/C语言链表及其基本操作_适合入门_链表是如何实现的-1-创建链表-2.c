struct nod* creat(int n)
{
	struct nod * head = (struct nod *)malloc(sizeof(struct nod));
	struct nod * end=head;
	
	for(int i=0;i<n;++i)
	{
		struct nod * temp = (struct nod *)malloc(sizeof(struct nod));
		scanf("%d",&temp->date);
		end->next = temp;
		end = temp;
	}
	end->next = NULL;
	
	return head;
}
