#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct sNode
{
	ElemType data;
	struct sNode * next;
};

int main()
{
	struct sNode *p,*q,*h;
	int i;
	h=p=malloc(sizeof(struct sNode));
	printf("Enter the values(q to quit)\n");
	for(i=0;i<10;i++)
	{
		q=malloc(sizeof(struct sNode));
		if(scanf("%d",&q->data)!=1)
			break;
			p->next=q;
			p=q;
	}
	p->next=NULL;
	p=h->next;
	while(p!=NULL)
	{
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
