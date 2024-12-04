#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STLEN 20
#include"nodestack.c"

int main()
{
	char str[STLEN];
	int i,length;
	int key;
	struct sNode *HS;

	InitStack(&HS);

	scanf("%s",str);
	length=strlen(str);

	for(i=0;i<length;i++)
		Push(&HS,str[i]);
	for(i=0;i<length;i++){
		if(str[i]==Pop(&HS))
			key=0;
		else{
			key=1;
			break;
		}
	}
	if(key==0)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
