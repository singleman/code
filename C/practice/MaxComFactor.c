#include<stdio.h>

int MaxComFactor(int a,int b);

int main()
{
	int m,n;
	printf("please input two number:");
	scanf("%d%d",&m,&n);
	printf("%d divide %d = %d\n",m,n,m%n);
	printf("%d divide %d = %d\n",n,m,n%m);
	printf("The Max common factor of %d and %d is %d\n",m,n,MaxComFactor(m,n));
}

int MaxComFactor(int a,int b)
{
	int remain;
	while(a%b!=0)
	{
		remain=a%b;
		a=b;
		b=remain;
	}
	return b;
}
