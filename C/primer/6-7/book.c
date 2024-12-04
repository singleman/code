#include<stdio.h>
#include<string.h>
char *s_gets(char *st,int n);
#define MAXTITL 41
#define MAXAUTL 31
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library;
	struct book *pst;
	pst = &library;

	printf("Please enter the book title.\n");
	s_gets(library.title,MAXTITL);
	//fgets(library.title,MAXTITL,stdin);
	//scanf("%s",&library.title);
	//gets(library.title);
	printf("Please enter the book author.\n");
	s_gets(library.author,MAXAUTL);
	//scanf("%s",&library.author);//gets(library.author);
	printf("Please enter the book value.\n");
	scanf("%f",&library.value);
	printf("%s by %s :$%.2f\n",library.title,pst->author,library.value);
	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find = strchr(st,'\n');
		if(find)
			*find='\0';
		else
			while(getchar()!='\n')// the mean of 0 n 
			continue;
	}
	return ret_val;
}
