#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

char * s_gets(char *st, int n);
int main()
{
	FILE *in, *out;
	char infile[LEN],outfile[LEN];
	int ch;
	puts("Enter the name of the source file:");
	s_gets(infile,LEN);
	if(( in = fopen(infile,"r")) ==NULL)
	{
		printf("error\n");
		exit(1);
	}

	puts("Enter the name of the target file:");
	s_gets(outfile,LEN);
	if(( out = fopen(outfile,"w")) ==NULL)
	{
		printf("erro2r\n");
		exit(1);
	}

       	/*while( (fgets(infile, LEN, stdin)) != NULL && ((in = fopen(infile,"r"))==NULL))
	{
		printf("The files doesn't exsit, input again:\n");
	}
	puts("Enter the name of the target file:");
	while( (fgets(outfile, LEN, stdin)) != NULL && ((out =fopen(outfile,"w"))==NULL))
	{
		printf("the \n");
	}
	*/
	while((ch =getc(in)) != EOF)
		putc(ch,out);
	fclose(in);
	fclose(out);	


	return 0;
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	char * find;

	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find = strchr(st,'\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}

