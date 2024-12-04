void InitList(struct sNode **HL)
{
	*HL = NULL;
}

void ClearList(struct sNode **HL)
{
	struct sNode *cp, *np;
	cp = *HL;
	while(cp != NULL)
	{
		np = cp->next;
		free(cp);
		cp = np;
	}

	*HL = NULL;
}

int SizeList(struct sNode *HL)
{
	int i = 0;
	while(HL != NULL)
	{
		i++;
		HL = HL->next;
	}
	return i;
}

int EmptyList(struct sNode *HL)
{
	if(HL = NULL)
		return 1;
	else
		return 0;
}

ElemType GetPosElem(struct sNode * HL, int pos)
{
	int i = 0;
	if (pos < 1)
	{
		printf("invalid postion!\n");
		exit(1);
	}
	while (HL != NULL)
	{
		i++;
		if(i == pos)
			break;
		HL = HL->next;
	}
	if(HL != NULL)
		return HL->data;
	else
	{
		printf("out of range\n");
		exit(2);
	}
}

void TraverseList(struct sNode * HL)
{
	while(HL != NULL)
	{
		printf("%5d",HL->data);
		HL = HL->next;
	}
	printf("\n");
}

ElemType * FindList(struct sNode * HL, ElemType x)
{
	while(HL != NULL)
	{
		if(HL->data == x) 
			return &HL->data;
		else
			HL = HL->next;
	}
	return NULL;
}

int UpdatePosList( struct sNode * HL, int pos, ElemType x)
{
	int i=0;
	struct sNode * p = HL;
	while(p != NULL)
	{
		i++;
		if (pos == i)
			break;
		else
			p = p->next;
	}
	if( pos == i)
	{
		p->data = x;
		return 1;
	}
	else
		return 0;
}

void InsertFirstList(struct sNode **HL, ElemType x)
{
	struct sNode *newp;
	newp = malloc(sizeof(struct sNode));
	if( newp == NULL)
	{
		printf("out of memory!\n");
		exit(1);
	}
	newp->data = x;
	newp->next = *HL;
	*HL = newp;
}

void InsertLastList(struct sNode **HL, ElemType x)
{
	struct sNode *newp;
	newp = malloc(sizeof(struct sNode));
	if(newp == NULL)
	{
		printf("out of memory,quit!\n");
		exit(1);
	}
	newp->data = x;
	newp->next = NULL;
	if(*HL == NULL)
		*HL = newp;
	else
	{
		struct sNode *p=*HL;
		while(p->next != NULL)
			p = p->next;
		p->next = newp;
	}
}

int InsertPosList(struct sNode **HL, int pos, ElemType x)
{
	int i = 0;
	struct sNode *newp,*cp,*ap;
	if(pos < 0)
	{
		printf("postion is valid!\n");
		return 0;
	}
	cp = *HL;
	ap = NULL;
	while(cp != NULL)
	{
		i++;
		if (pos == i)
			break;
		else
		{
			ap = cp;
			cp = cp->next;
		}
	}
	newp = malloc(sizeof(struct sNode));
	if(newp == NULL)
	{
		printf("out of memory!\n");
		return 0;
	}
	newp->data = x;
	if(ap == NULL)
	{
		newp->next = cp;
		*HL = newp;
	}
	else
	{
		newp->next = cp;
		ap->next = newp;
	}
	return 1;
}

int InsertOrderList( struct sNode **HL, ElemType x)
{
	struct sNode *cp,*ap,*newp;
	cp = *HL;
	ap = NULL;
	newp = malloc(sizeof(struct sNode));
	if(newp == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}
	newp->data=x;
	if(cp == NULL || x < cp->data)
	{
		newp->next = cp;
		*HL = newp;
		return 0;
	}
	while( cp != NULL)
	{
		if (x < cp->data)
			break;
		else
		{
			ap = cp;
			cp =cp->next;
		}
	}
	newp->next = cp;
	ap->next = newp;
	return 0;
}

ElemType DeleteFirstList(struct sNode **HL)
{
	ElemType temp;
	struct sNode *p;
	p = *HL;
	if (*HL == NULL)
	{
		printf("empty liner\n");
		exit(1);
	}
	*HL= (*HL)->next;
	temp = p->data;
	free(p);
	return temp;
}

ElemType DeleteLastList(struct sNode **HL)
{
	ElemType temp;
	struct sNode *cp,*ap;
	cp = *HL;
	ap = NULL;
	if( cp == NULL)
	{
		printf("empty liner\n");
		exit(1);
	}
	while(cp->next != NULL)
	{
		ap = cp;
		cp = cp->next;
	}
	if(ap == NULL)
		*HL = NULL;
	else
		ap->next = NULL;
	temp = cp->data;
	free(cp);
	return temp;
}

ElemType DeletePosList(struct sNode **HL, int pos)
{
	int i=0;
	ElemType temp;
	struct sNode *cp = *HL;
	struct sNode *ap = NULL;
	if(cp == NULL || pos < 0)
	{
		printf("empty or invalid pos\n");
		exit(1);
	}
	while(cp != NULL)
	{
		i++;
		if (i == pos)
			break;
		ap = cp;
		cp = cp->next;
	}
	if(cp == NULL)
	{
		printf("the postion is out of range\n");
		exit(1);
	}
	if(pos == 1)
		*HL = (*HL)->next;
	else
		ap->next = cp->next;
	temp = cp->data;
	free(cp);
	return temp;
}

int DeleteValueList(struct sNode **HL, ElemType x)
{
	struct sNode *cp = *HL;
	struct sNode *ap = NULL;
	while(cp != NULL)
	{
		if(cp->data == x)
			break;
		ap = cp;
		cp = cp->next;
	}
	if(cp == NULL)
		return 0;
	if(ap == NULL)
		*HL = (*HL)->next;
	else
		ap->next = cp->next;
	free(cp);
	return 1;
}

int ReverseList(struct sNode **HL)
{
	struct sNode *head,*first,*rever,*last,*l_sec;
	int switch_rever=1;
	head=*HL;
	first=*HL;

	if(head==NULL)
	{
		printf("empty list\n");
		return 1;
	}
	while(head->next!=NULL)
	{
		l_sec=head;
		head=head->next;
	}
	last=head;
	rever=head;
	l_sec->next=NULL;

	while(switch_rever)
	{
		head=first;
		switch_rever=0;
		while(head->next!=NULL)
		{
			switch_rever=1;
			l_sec=head;
			head=head->next;
		}

		l_sec->next=NULL;
		rever->next=head;
		rever=head;

	}
	*HL=last;
	return 0;
}

ElemType FindMaxList(struct sNode *HL)
{
	struct sNode *p,*q;
	ElemType max,temp;
	p=HL;
	q=p->next;
	max=p->data;
	if(p==NULL){
		printf("empty node!\n");
		exit(1);
	}
	if(q==NULL)
		return p->data;
	while(q!=NULL){
		if(p->data > q->data)
			temp = p->data;
		else
			temp = q->data;
		if(temp > max)
			max = temp;
		p=q;
		q=q->next;
	}
	return max;

}

void MergeList(struct sNode **HL,struct sNode **SL)
{
	struct sNode *head,*traver,*tra_temp,*front,*back;
	int i=0,j=0;
	if((*HL)->data < (*SL)->data){
		head=*HL;	//save the head pointer
		traver=*SL;	//traversal the snode;
	}
	else{
		head=*SL;
		traver=*HL;
	}
	tra_temp=traver;

	while(traver!=NULL){
		tra_temp=tra_temp->next;//save the next start;
		front=head;		//front and back for the insert
		back=front->next;
		i++;
		while(back!=NULL){
			j++;
			if(traver->data < back->data){
				traver->next=back;
				front->next=traver;
				break;
			}
			else{
				front=back;
				back=back->next;
				if(back==NULL){
					front->next=traver;
					traver->next=back;
				}
			}
		}
		traver=tra_temp;
	}
	*HL=head;
	*SL=head;
}

void printListFromTailToHead(struct sNode *HL)
{
	if(HL!=NULL){
		if(HL->next!=NULL)
			printListFromTailToHead(HL->next);
		printf("%5d",HL->data);
	}
}
