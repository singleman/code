#include <stdio.h>
#include <stdlib.h>
#define NN 12 
#define MM 20

typedef int ElemType;
struct sNode
{
	ElemType data;
	struct sNode* next;
};
#include "snode.c"

int main()
{
	int a[NN];
	int b[NN]={7,3,1};
	int i;
	struct sNode *p,*h,*s;
	InitList(&p);
/*	
	for(i = 0;i < NN;i++)
		InsertFirstList(&p,a[i]);
	for(i = 0;i < NN;i++)
		InsertFirstList(&h,b[i]);
	MergeList(&p,&h);
	TraverseList(p);
	*/

	for(i = 0;i < NN;i++)
		a[i] = rand()%MM;
	printf("radom number:");
	for(i = 0;i < NN;i++)
		printf("%5d",a[i]);
	printf("\n");
	printf("radom in reversal:");
	for(i = 0;i < NN;i++)
		InsertFirstList(&p,a[i]);
	TraverseList(p);
	printf("the max number is %d\n",FindMaxList(p));
	printf("reveral again:");
	ReverseList(&p);
	TraverseList(p);
	printf("\n");

	printf("the lenth of linerlist is %d\n",SizeList(p));
	for(h = p;h!=NULL; h = h->next)
		while(DeleteValueList(&(h->next),h->data));
	printf("remove duplicate:");
	TraverseList(p);
	printf("the lenth of linerlist is %d\n",SizeList(p));
	h = NULL;
	for (s = p; s!=NULL; s=s->next)
		InsertOrderList(&h,s->data);
	printf("number in order:");
	TraverseList(h);
	MergeList(&h,&p);
	TraverseList(h);
	ClearList(&p);
}

