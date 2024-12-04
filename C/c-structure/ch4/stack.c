#define int ElemType
typedef struct StackSq{
	ElemType *stack;
	int top;
	int MaxSize;
}StackSq;

void InitStack(StackSq *S,int ms)
{
	if(ms<0){
		printf("ms is invalid!\n");
		exit(1);
	}
	S->MaxSize = ms;
	S->stack=malloc(S->MaxSize*sizeof(ElemType));
	if(!S->stack){
		printf("no space!\n");
		exit(1);
	}
	s->top = -1;
}

void Push(StackSq *S,ElemType x)
{
	if(S->top==S->MaxSize)
		againMalloc(S);
	S->top++;
	S->stack[S->top]=x;
}

void againMalloc(StackSq *S)
{
	ElemType *p;
	p = realloc(S->stack,2*S->MaxSize*sizeof(ElemType));
	if(!p){
		printf("no space!\n");
		exit(1);
	}
	S->stack=p;
	S->MaxSize=2*S->MaxSize;
}

ElemType Pop(StackSq *S)
{
	if(S->top==-1){
		printf("stack if empty!\n");
		exit(1);
	}
	S->top--;
	return S->stack[S->top+1];
}

ElemType Peek(StackSq *S)
{
	if(S->top==-1){
		printf("stack if empty!\n");
		exit(1);
	}
	return S->stack[S->top];
}
