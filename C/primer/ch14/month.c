#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct month{
	char mon[10];
	char monabb[4];
	int num,days;
};
int inputmonth(struct month *pt);

int main()
{
	struct month year[12];
	FILE *in;
	int i;

	in=fopen("month","rb");
	for(i=0;i<12;i++)
		fscanf(in,"%d %s %s %d \n",&(year[i].num),((year+i)->mon),&((year+i)->monabb),&((year+i)->days));
		//printf("%d %s %s %d\n",year[i].num,(year+i)->mon,(year+i)->monabb,(year+i)->days);
	inputmonth(year);

	return 0;
}

int inputmonth(struct month *pt)
{
	char input[10];
	int i,j;
	(scanf("%s",input));
	{
		for(i=0;i<12;i++)
		{
			if(strcmp((pt+i)->mon,input)==0)
				break;
			if(strcmp((pt+i)->monabb,input)==0)
				break;
			if(input[0]>='0' && input[0]<='9')
			{
				i=atoi(input);
				printf("it %d month\n",i);
				return i;
			}
		}
	}
	printf("it %d month\n",++i);
	return ++i;
}
