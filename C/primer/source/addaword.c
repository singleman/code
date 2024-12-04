#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];

	if((fp=fopen("words","a+")) == NULL)
	{
		fprintf(stdout,"Can't open \"words\" file.\n");
		exit(EXIT_FAILURE);
	}

	puts("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
	//while((fscanf(stdin,"%40s",words) ==1) && (words[0]!='\n'))
	while(fgets(words,MAX,stdin)!=NULL && words[0]!='\n')
		fprintf(fp,"%s\n",words);
	puts("File contents:");
	rewind(fp); 
	while(fscanf(fp,"%s",words)==1)
		//fputs(words,stdout);
		puts(words);
	puts("Done!");
	if(fclose(fp)!=0)
		fprintf(stderr,"Error closing file\n");
	return 0;
}
