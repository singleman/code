#include<stdio.h>
#include<stdlib.h>
#define SLEN 40
typedef int ElemType;
struct List{
	ElemType *list;
	int size;
	int MaxSize;
};

void InitList(struct List *pst,int ms)
{
	if(ms < 0)
	{
		printf("ms is not correct!\n");
		exit(1);
	}	
	pst->MaxSize=ms;
	pst->list=(ElemType *)malloc(ms*sizeof(ElemType));
	if(!pst->list)
	{
		printf("Memory allocation failed.Goodbye\n");
		exit(1);
	}
	pst->size = 0;
}

void ClearList(struct List *pst)
{
	if(pst->list != NULL)
	{
		free(pst->list);
		pst->list=NULL;	//why?
		pst->size=pst->MaxSize=0;
	}
}

int SizeList(struct List *pst)
{
	return pst->size;
}

int EmptyList(struct List *pst)
{
	if(pst->size=0)
		return 0;
	else
		return 1;
}

ElemType GetElemPos(struct List *pst,int pos)
{
	if(pos<1 || pos > pst->size)
	{
		printf("the postion is out of the range\n");
		exit(1);
	}
	return pst->list[pos-1];
}

void TraverseList(struct List *pst)
{
	int i;
	printf("Now we printf the content of linerlist:\n");
	for(i=0;i<pst->size;i++)
	{
		printf("%4d ",pst->list[i]);
		if(i%7==6)
			putchar('\n');
	}
	printf("\n");
}

int FindList(struct List *pst, ElemType x)
{
	int i;
	for(i=0;i < pst->size; i++)
		if(pst->list[i]==x)
			return i;
	printf("No Element is equal to %d\n",x);
	return -1;
}

int UpdatePosList(struct List *pst, int pos, ElemType x)
{
	if (pos<1||pos>pst->size)
		return 0;
	pst->list[pos-1]=x;
	return 1;
}

void againMalloc(struct List *pst)
{
	ElemType *temp;
	temp = (ElemType *)realloc(pst->list,2*pst->MaxSize*sizeof(ElemType));
	if(!temp)
	{
		printf("Insufficient storage space\n");
		exit(1);
	}
	pst->list=temp;
	pst->MaxSize= 2*pst->MaxSize;
}

void InsertFirstList(struct List *pst, ElemType x)
{
	int i;
	if(pst->size==pst->MaxSize)
		againMalloc(pst);
	for(i=pst->size-1;i>=0;i--)
		pst->list[i+1]=pst->list[i];
	pst->list[0]=x;
	pst->size++;
}

void InsertLastList(struct List *pst,ElemType x)
{
	int i;
	if(pst->size==pst->MaxSize)
		againMalloc(pst);
	pst->list[pst->size]=x;
	pst->size++;
}

int InsertPosList(struct List *pst,int pos, ElemType x)
{
	int i;
	if(pos<1||pos>pst->size+1)
	{
		printf("The position is out of range\n");
		return 0;
	}
	if(pst->size==pst->MaxSize)
		againMalloc(pst);
	for(i=pst->size-1;i>=pos-1;i--)
		pst->list[i+1]=pst->list[i];
	pst->list[pos-1]=x;
	pst->size++;
	return 1;
}

void InsertOrderList(struct List *pst, ElemType x)
{
	int i,j;
	if(pst->size==pst->MaxSize)
		againMalloc(pst);
	for(i=0;i<pst->size;i++)
		if(x<pst->list[i]) break;
	for(j=pst->size-1;j>=i;j--)
		pst->list[j+1]=pst->list[j];
	pst->list[i]=x;
	pst->size++;
}

ElemType DeleteFirstList(struct List *pst)
{
	ElemType temp;
	int i;
	if(pst->size==0)
	{
		printf("Liner list has no element\n");
		exit(1);
	}
	temp=pst->list[0];
	for(i=1;i<pst->size;i++)
		pst->list[i-1]=pst->list[i];
	return temp;
}

ElemType DeleteLastList(struct List *pst)
{
	if(pst->size==0)
	{
		printf("Liner list has no element\n");
		exit(1);
	}
	pst->size--;
	return pst->list[pst->size];
}

ElemType DeletePosList(struct List *pst,int pos)
{
	ElemType temp;
	int i;
	if(pos<1||pos>pst->size)
	{
		printf("the postion is out of the range\n");
		exit(1);
	}
	temp=pst->list[pos-1];
	for(i=pos;i<pst->size;i++)
		pst->list[i-1]=pst->list[i];
	pst->size--;
	return temp;
}

int DeleteValueList(struct List *pst,ElemType x)
{
	int i,j;
	for(i=0;i<pst->size;i++)
		if(pst->list[i]==x)break;
	if(i==pst->size)
		return 0;
	for(j=i;j<pst->size;j++)
		pst->list[j]=pst->list[j+1];
	pst->size--;
	return 1;
}

int main(void)
{
	int i,j,max;
	FILE *out,*in;
	ElemType temp[SLEN];
	struct List L;
	struct List *pt;
	pt = &L;
	InitList(&L,4);
	i=0;
	/*
	 * if(( in = fopen("infile","r")) == NULL)
	{
		printf("Can't open the infile!\n");
		exit(1);
	}
	while( i< SLEN && fscanf( in, "%d", &temp[i]) ==1)
	{
		if(i==0)
			InsertLastList(&L,temp[i]);
		else
			InsertOrderList(&L,temp[i]);
		i++;
	}
	*/
	
	printf("Please input the size of the list:\n");
	scanf("%d",&max);
	InitList(&L,max);
	printf("Please input the element(q to quit)\n");
	i = 0;
	while(i<max && scanf("%d",&(L.list[i]))==1)
	{
		pt->size++;
		i++;
	}
	

	/*int maxsize=6;
	int input[10]={2,4,6,8,10,12,14,16,18,20};
	int j;
	for(j=0;j<10;j++)
		InsertLastList(&L,input[j]);*/

	//InsertPosList(&L,2,9);
	//printf("these are the input numbers in orders:\n");
	TraverseList(&L);
	if((out = fopen("outfile","w"))==NULL)
	{
		fprintf(stderr,"Can't create output file.\n");
		exit(3);
	}
	for(j=0;j<L.size;j++)
	{
		fprintf(out,"%d  ",L.list[j]);
		if( i%5==1 )
			printf("\n");
	}
	fclose(out);
	fclose(in);

	return 0;
}
