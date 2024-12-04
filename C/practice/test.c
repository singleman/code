#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	if( argc == 1)
		{
			printf("usage\n");
			exit(1);
		}
	int i;
	char dst[128],*pstr=argv[1];
	for(i=0;*pstr;i++)
		dst[i]=toupper(*pstr++);
	dst[i]='\n';
	printf("%s",dst);
	return 0;

} 
