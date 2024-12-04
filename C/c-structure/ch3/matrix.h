#ifndef _MATRIX_H
#define _MATRIX_H
struct Triple{
	int row,col;
	ElemType val;
};

struct SMatrix{
	int m,n,t;
	struct Triple sm[MaxTerms+1];
};

struct TripleNode{
	int row,col;
	ELemType val;
	struct TripleNode *next;
};

struct LMatrix{
	int m,n,t;
	struct TripleNode * lm[MaxRows+1];
};

struct CrossNode{
	int row,col;
	ElemType val;
	struct CrossNode *down,*right;
};

struct CLMatrix{
	int m,n,t;
	struct CrossNode *rm[MaxRows+1];
	struct CrossNode *cm[MaxRows+1];
};

void InitSMatrix(struct SMatrix *M);
void InitLMatrix(struct LMatrix *M);
void InitCLMatrix(struct CLMatrix *M);
void InputSMatrix(struct SMatrix *M,int m,int n);
void InputLMatrix(struct LMatrix *M,int m,int n);
void InputCLMatrix(struct CLMatrix *M,int m,int n);
void OutputSMatrixt(struct Smatrix *M);
void OutputLMatrix(struct LMatrix *M);
void OutputCLMatrix(struct CLMatrix *M);

#endif
