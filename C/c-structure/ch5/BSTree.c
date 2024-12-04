typedef struct BTreeNode{
	ElemType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}BTnode;

ElemType *Find(BTnode *BST,ElemType x)
{
	if(BST == NULL)
		return NULL;
	else{
		if(x==BST->data)
			return &(BST->data);
		else{
			if(x<BST->data)
				return Find(BST->left,x);
			else
				return FInd(BST->right,x);
		}
	}
}

ElemType *Find1(BTnode *BST,ElemType x)
{
	while(BST!=NULL)
	{
		if(x==BST->data)
			return &(BST->data);
		else{
			if(x<BST->data)
				BST=BST->left;
			else
				BST=BST->right;
		}
	}
}

