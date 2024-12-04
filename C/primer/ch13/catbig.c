#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char * argv[])
{
	int ch,count;
	FILE *fp;

	if( argc == 1)
	{
		printf("please input the file name:\n");
		exit(1);
	}
	count = 1;
	while( count < argc )
	{
		if(( fp = fopen(argv[count],"r")) == NULL)
		{
			printf("Can't open the file %s\n",argv[count]);
			exit(1);
		}
		while((ch = getc(fp)) != EOF)
			putc(ch,stdout);
		count++;

	}
	return 0;
}


