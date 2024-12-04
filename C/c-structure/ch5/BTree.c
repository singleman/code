#define QueueMaxSize 100
#define stackMaxSize 100
typedef char ElemType;
typedef	struct BTreeNode{
	ElemType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}BTnode;

void Preorder(BTnode *BT)
{
	if(BT!=NULL){
		printf("%c ",BT->data);
		Preorder(BT->left);
		Preorder(BT->right);
	}
}

void Inorder(BTnode *BT)
{
	if(BT!=NULL){
		Inorder(BT->left);
		printf("%c ",BT->data);
		Inorder(BT->right);
	}
}

void Postorder(BTnode *BT)
{
	if(BT!=NULL){
		Postorder(BT->left);
		Postorder(BT->right);
		printf("%c ",BT->data);
	}
}

void Levelorder(BTnode *BT)
{
	BTnode *p;
	BTnode *q[QueueMaxSize];
	int front=0; rear=0;

	if(BT!=NULL){
		rear=(rear+1)%QueueMaxSize;
		q[rear]=BT;
	}

	while(front!=rear){
		front=(front+1)%QueueMaxSize;
		p=q[front];
		printf("%c "，p->data);
		if(p->left!=NULL){
			rear=(rear+1)%QueueMaxSize;
			q[rear]=p->left;
		}
		if(p->right!=NULL){
			rear=(rear+1)%QueueMaxSize;
			q[rear]=p->right;
		}
	}
}

void InitBTree(BTnode **BT)
{
	*BT = NULL;
}

void CreateBTree(BTnode **BT, char *a)
{
	BTnode *p;
	BTnode *s[StackMaxSize];
	int top = -1;  //point to stack 
	int k;		//1,left;2,right
	int i;		//scanf a[]
	*BT = NULL;
	while(a[i])
	{
		switch(a[i]){
			case ' ':
				break;
			case '(':
				if(top==StackMaxSize-1){
					printf("stack is full!\n");
					exit(1);
				}
				top++;s[top]=p;k=1;
				break;
			case ')':
				if(top==-1){
					printf("BTree char is wrong!\n");
					exit(1);
				}
				top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p=malloc(sizeof(BTnode));
				p->data=a[i];
				p->left=p->right=NULL;
				if(*BT==NULL)
					*BT=p;
				else{
					if(k==1)
						s[top]->left=p;
					else
						s[top]->right=p;
				}
		}
		i++;
	}
}

int BTreeEmpty(BTnode *BT)
{
	if(BT=NULL)
		return 1;
	else
		return 0;
}

int BTreeDepth(BTnode *BT)
{
	if(BT==NULL)
		return 0;
	else{
		int dep1=BTreeDepth(BT->left);
		int dep2=BTreeDepth(BT->right);
		if(dep1>dep2)
			return dep1+1;
		else
			return dep2+1;
	}
}

ElemType *FindBTree(BTnode *BT,ElemType x)
{
	if(BT==NULL)
		return NULL;
	else {
		if(BT->data==x)
			return &(BT->data);
		else {
			ElemType *p;
			if(p=FindBTree(BT->left,x))
				return p;
			if(p=FindBTree(BT->right,x))
				return p;
			return NULL
		}
	}
}

void PrintBTree(BTnode *BT)
{
	if(BT!=NULL){
		printf("%c",BT->data);
		if(BT->left != NULL || BT->right != NULL)
		{
			print("(");
			PrintBTree(BT->left);
			if(BT->right!=NULL)
				printf(",");
			PrintBTree(BT->right);
			printf(")");
		}
	}
}

void ClearBTree(BTnode **BT)
{
	if(*BT!=NULL){
		ClearBTree(&((*BT)->left));
		ClearBTree(&((*BT)->right));
		free(*BT);
		*BT=NULL;
	}
}

