#include "matrix.h"

void InitSMatrix(struct SMatrix *M)
{
	M->m=0;
	M->n=0;
	M->t=0;
}

void InitLMatrix(struct LMatrix *M)
{
	int i;
	M->m=0;
	M->n=0;
	M->t=0;
	for(i=1;i<=MaxRows;i++)
		M->lm[i]=NULL;
}

void InitCLMatrix(struct CLMatrix *M)
{
	int i;
	M->m=0;
	M->n=0;
	M->t=0;
	for(i=1;i<=MaxRows;i++)
		M->rm[i]=NULL;
	for(i=1;i<=MaxColumns;i++)
		M->cm[i]=NULL;
}

void InputSMatrix(struct SMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	ELemType val;
	M->m=m;
	M->n=n;
	printf("input the row col value:\n");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		k++;
		M->sm[k].row=row;
		M->sm[k].col=col;
		M->sm[k].val=val;
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

void InputLMatrix(struct LMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	ElemType val;
	M->m=m;M->n=n;

	printf("input the row col value:\n");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		struct TripleNode *cp,*newp;
		k++;

		newp=malloc(sizeof(struct TripleNode));
		newp->row=row;
		newp->col=col;
		newp->val=val;
		newp->next=NULL;

		cp=M->lm[row];
		if(cp==NULL)
			M->lm[row]=newp;
		else{
			while(cp->next!=NULL)
				cp=cp->next;
			cp->next=newp;
		}
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

void InputCLMatrix(struct CLMatrix *M,int m,int n)
{
	int k=0;
	int row,col;
	ElemType val;
	M->m=m;M->n=n;

	printf("input the row col value:\n");
	scanf("%d %d %d",&row,&col,&val);
	while(row!=0){
		struct CrossNode *cp,*newp;
		k++;

		newp=malloc(sizeof(struct CrossNode));
		newp->row=row;
		newp->col=col;
		newp->val=val;
		newp->right=newp->down=NULL;

		cp=M->rm[row];
		if(cp==NULL)
			M->rm[row]=newp;
		else{
			while(cp->right!=NULL)
				cp=cp->right;
			cp->right=newp;
		}
		cp=M->cm[col];
		if(cp==NULL)
			M->cm[col]=newp;
		else{
			while(cp->down!=NULL)
				cp=cp->down;
			cp->down=newp;
		}
		scanf("%d %d %d",&row,&col,&val);
	}
	M->t=k;
}

void OutputSMatrix(struct SMatrix *M)
{
	int i;
	printf("(");
	for(i=1;i<M->t;i++)
		printf("(%d,%d,%d),",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	if(M->t!=0)
		printf("(%d,%d,%d)",M->sm[i].row,M->sm[i].col,M->sm[i].val);
	printf(")");
}

void OutputLMatrix(struct LMatrix *M)
{
	int i;
	struct TripleNode *p;
	printf("{\n");
	for(i=1;i<=M->m;i++){
		for(p=M->lm[i];p!=NULL;p=p->next)
			printf("(%d,%d,%d),",p->row,p->col,p->val);
		printf("\n");
	}
	printf("}");
}

struct SMatrix * TransposeSMatrix(struct SMatrix *M)
{
	int m,n,t;
	int k,i,col;

	struct SMatrix *S;
	S=malloc(sizeof(struct SMatrix));
	InitSMatrix(S);
	m=M->m; n=M->n; t=M->t;
	S->m=n; S->n=m; S->t=t;
	if(t==0)
		return S;
	k=1;
	for(col=1;col<=n;col++){
		for(i=1;i<=t;i++)
			if(M->sm[i].col==col){
				S->sm[k].row=col;
				S->sm[k].col=M->sm[i].row;
				S->sm[k].val=M->sm[i].val;
				k++;
			}
	}
	return S;
}

struct LMatrix * AddMatrix(struct LMatrix *M1,struct LMatrix *M2)
{
	return 
}
