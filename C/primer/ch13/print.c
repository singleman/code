#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 40

char * s_gets(char * st,int n );

int main()
{
	FILE *source;
	int ch;
	long count,last;
	char file[LEN],output[LEN];

	puts("Enter the name of th file to be print:");
	s_gets(file,LEN);
	if((source = fopen(file,"rb"))==NULL)
	{
		printf("reverse can't open %s\n!!",file);
		exit(1);
	}
	
	puts("Enter the location for start:");
	//last=ftell(source);
	while(scanf("%ld",&count)!=0 )
	{
		fseek(source,count,SEEK_SET);
		fgets(output,LEN,source);
		fputs(output,stdout);
		/*while(((ch = getc(source))!=EOF) && (ch !='\n'))
			putc(ch,stdout);
		putchar('\n');
		*/
	}
	fclose(source);
	return 0;
}

char * s_gets(char * st, int n)
{
	char *ret_val;
	char *find;
	
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
			*find = '\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}
