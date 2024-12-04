#include<stdio.h>

#define LEN 10
/*
struct coff{
	float *pt;
	int size,Maxsize;
};
*/

double plfun(float *pt,int n,float x);
int main()
{
	float pt[4]={1.0,2,4,5};
	float x[3]={2,1,3};
	int i;

	for(i=0;i<3;i++)
		printf("x[%d]=%f,	ply(%d)=%f\n",i,x[i],i,plfun(pt,4,x[i]));
	return 0;
}
