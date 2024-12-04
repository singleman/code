#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{	
	int row,col;
	int data[20][30];
	char ch[20][31];
	FILE *source,*pic;


	source=fopen("randata","wr");
	pic=fopen("picture","w");
	//srand(11);
	srand(time(0));
	for(row=0;row<20;row++)
	{
		for(col=0;col<30;col++)
		{
			data[row][col]=rand()%10;
			fprintf(source,"%4d ",data[row][col]);
		}
		fprintf(source,"\n");
	}

	rewind(source);
	for(row=0;row<20;row++)
	{
		for(col=0;col<31;col++)
		{
			if(col!=30)
			{
				fscanf(source,"%d",data[row][col]);
				ch[row][col]=(char)(data[row][col]+31);
			}
			else
				ch[row][col]='\0';
			fprintf(pic,"%c ",ch[row][col]);

		}
		fprintf(pic,"\n");
	}

	fclose(pic);
	fclose(source);
	
	return 0;
}

