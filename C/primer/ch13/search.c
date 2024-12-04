#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 10

int main(int argc, char * argv[])
{
	FILE *fp;
	char words[LEN];

	if(argc != 3)
	{
		printf("input error\n");
		exit(1);
	}
	while( (fp = fopen(argv[2],"r")) ==NULL)
	{
		printf("file %s can't be open\n",argv[2]);
		exit(1);
	}

	while( fgets(words,LEN,fp)!=NULL)
	{
		if(strstr(words,argv[1]))
			fputs(words,stdout);
	}
	return 0;
}
