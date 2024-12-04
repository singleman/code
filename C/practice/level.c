#include<stdio.h>

int main()
{
	int score,level;

	while( scanf("%d",&score)!=1 || score>100 || score<0 )
	{
		printf("error!\n");
		while(getchar()!='\n')
			continue;
	}  //input the score;

	level=score/10;
	switch(level)
	{
		case 10:
			printf("your level is A--%d\n",score);
			break;
		case 9:
			printf("your level is B--%d\n",score);
			break;
		case 8:
			printf("your level is C--%d\n",score);
			break;
		case 7:
			printf("your level is D--%d\n",score);
			break;
		case 6:
			printf("your level is E--%d\n",score);
			break;
		default:
			printf("your level is F--%d\n",score);
			break;
	}

	return 0;
}
