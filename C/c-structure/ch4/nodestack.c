typedef char ElemType;

struct sNode{
	ElemType data;
	struct sNode *next;
};


void InitStack(struct sNode **HS)
{
	*HS = NULL;
}

void Push(struct sNode **HS, ElemType x)
{
	struct sNode *newp;
	newp = malloc(sizeof(struct sNode));
	if(newp == NULL){
		printf("empty store\n");
		exit(1);
	}
	newp->data = x;
	newp->next = *HS;
	*HS = newp;
}

ElemType Pop(struct sNode **HS)
{
	struct sNode *p;
	ElemType temp;
	if(*HS == NULL){
		printf("empty stack\n!");
		exit(1);
	}
	p = *HS;
	*HS = p->next;
	temp = p->data;
	free(p);
	return temp;
}

ElemType Peek(struct sNode *HS)
{
	if(HS == NULL){
		printf("empty stack\n!");
		exit(1);
	}
	return HS->data;
}


