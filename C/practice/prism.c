#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prism(int n);
void resolve(int n);

int main()
{
	int n;
	//printf("input the number:\n");
	//scanf("%d",&n);
	for(n=1;n<100;n++)
		resolve(n);

	return 0;
}

int prism(int n)
{
	int key,i;
	if(n<3)
		return 0;
	if((n%2)==0)
	{
	//	printf("%d is a even",n);
		return 0;
	}
	else
	{
		key=(int)sqrt(n)+1;
		for(i=2;i<key;i++)
		{
			if((n%i)==0)
			{
	//			printf("%d is an odd, but not a prime",n);
				return 0;
			}
		}
	}
	return 1;
}

void resolve(int n)
{
	int key,head,tail;
	FILE *fp;
	fp=fopen("prism","a+");

	key=(int)(n/2)+1;
	for(head=3;head<key;head++)
	{
		tail=n-head;
		if(tail<=0)
			exit(1);
		if(prism(head)&&prism(tail))
		{
			printf("%d = %d + %d;\n",n,head,tail);
			fprintf(fp,"%d = %d + %d;\n",n,head,tail);
		}
	}
	fclose(fp);

}
