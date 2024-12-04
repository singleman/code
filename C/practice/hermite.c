#include<stdio.h>

float herm(int n,float x);
int main()
{
	int n;
	float x,hermite;
	scanf("%d",&n);
	scanf("%f",&x);

	hermite=herm(n,x);
	printf("%f",hermite);

	return 0;
}

float herm(int n,float x)
{
	if(n==0)
		return 1;
	else
	{
		if(n==1)
			return 2*x;
		else
			return 2*x*herm(n-1,x)-2*(n-1)*herm(n-2,x);
	}
}

