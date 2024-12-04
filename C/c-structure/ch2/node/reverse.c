#include<stdio.h>
#include<stdlib.h>
#define NN 10
#define MM 21

typedef int ElemType;
struct sNode{
	ElemType data;
	struct sNode *next;
};

#include "snode.c"

int main()
{
	struct sNode *p;
	int a[NN];
	int i;
	InitList(&p);

	for(i=0;i<NN;i++)
		a[i]=rand()%MM;
	for(i=0;i<NN;i++)
		printf("%5d",a[i]);
	printf("\n");
	for(i=0;i<NN;i++)
		InsertLastList(&p,a[i]);
	printListFromTailToHead(p);
	printf("\n");
	TraverseList(p);
	ClearList(&p);



	return 0;
}
