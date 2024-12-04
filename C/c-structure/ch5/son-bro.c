typedef int ElemType;
struct BSTree{
	ElemType data;
	struct BSTree *bro;
	struct BSTree *son;
}

int TreeHeight(struct BSTree *HS)
{
	if(HS==NULL)
		return 0;			//empty tree
	if(HS->bro==NULL || HS->son==NULL){	//子和兄有任一为空
		if(HS->bro != NULL)
			return TreeHeight(HS->bro); //子空，则返回兄弟的深度
		else{
			if(HS->son!=NULL)
				return TreeHeight(HS->son)+1; //兄空，返回子的深度再加上本身
			else
				return 1;	//都空，返回本身的深度
		}
	}
	else
		return max(TreeHeight(HS->son)+1,TreeHeight(HS->bro));//都不空，返回更深的,子和兄比较时候应该加上自己爹地
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

