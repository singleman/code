/*reverse.c -- displays a file in reverse order */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CNTL_Z '\032' /*EOF marker in DOS text files*/
#define SLEN 81
int main(void)
{
	char file[SLEN],name[SLEN];
	char ch;
	FILE *fp,*out;
	long count,last;

	puts("Enter the name of the file to be processed:");
	scanf("%80s",file);
	if((fp = fopen(file,"rb")) == NULL)
	{
		printf("reverse can't open %s\n",file);
		exit(EXIT_FAILURE);
	}
	strcpy(name,file);
	strcat(name,".bak");
	if((out = fopen(name,"w")) ==NULL)
	{
		fprintf(stderr,"Can't create output file.\n");
		exit(2);
	}
	fseek(fp,0L,SEEK_END); //go to the end of the file
	last = ftell(fp);
	for(count= 1L; count <= last;count++)
	{
		fseek(fp,-count,SEEK_END);//go backward
		ch=getc(fp);
		if(ch != CNTL_Z && ch!= '\r')
			//putc(ch,out);
			putchar(ch);
	}
	putchar('\n');
	if(fclose(fp)!=0 || fclose(out)!=0)
		fprintf(stderr,"Error in closing files\n");
	//fclose(fp);
	//fclose(out);

	return 0;
}

