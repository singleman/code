#include<stdio.h>
#include<math.h>


int main(void)
{

	int n;
	long double  e,temp;

	temp = 1.5;
	e=1;
	for(n=1;n;n++)
	{
		e=pow((1+1.0/n), n);
		if(fabs(temp-e)<pow(10,-10))
		{
			printf("when n=%d, the natual constant is %.100Lf\n",n,e);
			break;
		}
		temp=e;
	}


	return 0;
}
