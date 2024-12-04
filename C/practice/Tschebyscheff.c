#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float fun(int n,int x);
FILE *fp;
int main()
{
	time_t first,last;
	double duration;


	int x,n,i;
	float front_1,front,Tschebyscheff;
	scanf("%d%d",&n,&x);
	if((fp=fopen("tdat1.txt","a+"))==NULL)  //判断文件是否能够正常打开
    {
		printf("文件打开失败!\n");
		exit(0);
	}


	//非递归方法
	first=clock();
	//first=time(NULL);
	for(i=0;i<n+1;i++)
    {
        switch(i)
        {
            case 0:
                fprintf(fp,"T(%d,%d)=%.2f\n",i,x,1.00);
                front_1=1;
                break;
            case 1:
                fprintf(fp,"T(%d,%d)=%.2f\n",i,x,(float)x);
                front=x;
                break;
            default:
                Tschebyscheff=2*x*front-front_1;
                fprintf(fp,"T(%d,%d)=%.2f\n",i,x,Tschebyscheff);
                front_1=front;
                front=Tschebyscheff;
                break;
        }
    }
    //last=time(NULL);
    last=clock();
    duration=(double)(last-first);
    printf("Non recursive method takes %lf Milliseconds\n",duration);


    //递归
	first=clock();
	//first=time(NULL);
    for(i=0;i<n+1;i++)
    {
        fprintf(fp,"T(%d,%d)=%.2f\n",i,x,fun(i,x));
    }
    //last=time(NULL);
    last=clock();
    duration=(double)(last-first);
    printf("Non recursive method takes %lf Milliseconds\n",duration);

	fclose(fp);
	return 0;
}

float fun(int n,int x)
{
    if(n==0)
        return 1.0;
    else
    {
        if(n==1)
            return (float)x;
        else
            return 2*x*fun(n-1,x)-fun(n-2,x);
    }
}
