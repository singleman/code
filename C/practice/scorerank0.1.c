#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define LEN 40

char *s_get(char *st, int n);

int main()
{
	struct student{
		char name[LEN];
		int liter,math,english,total,rank;
	};
	/*struct rank{
		struct student *stu;
		int number;
		int maxsize;
	};

	struct rank *pt;
	pt=malloc(sizeof(struct rank));
	*/


	int i,j,flag,Maxsize;
	char option,source[LEN];

	Maxsize=8;
	struct student *pt,*temp;
	pt=malloc(Maxsize*sizeof(struct student));
	temp=malloc(sizeof(struct student));

	
	//while(s_get((pt->stu[0]).name,LEN) != NULL) double pt
	

	//input
	/*
	for(i=0;i<Maxsize;i++)
	{
		printf("please input the student name:\n");	
		s_get((pt+i)->name,LEN);   // pt[0].name (pt+1)->name
					//	printf("%s\n",pt[0].name);
		
			printf("please input the score:\n");	
			scanf("%d %d %d",&((pt+i)->liter),&((pt+i)->math),&((pt+i)->english));
			(pt+i)->total=(pt+i)->liter + (pt+i)->math + (pt+i)->english;
	
		printf("name: %4s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt+i)->name,(pt+i)->liter,(pt+i)->math,(pt+i)->english,(pt+i)->total);
		while(getchar()!='\n')
			continue;
	}
	*/
	
	FILE *in;
	in = fopen ("score","r");
	for(i=0;i<Maxsize;i++)
	{
		fscanf(in,"%s %d %d %d\n",(pt+i)->name,&((pt+i)->liter),&((pt+i)->math),&((pt+i)->english));
		(pt+i)->total=(pt+i)->liter + (pt+i)->math + (pt+i)->english;
		//printf("name: %4s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt+i)->name,(pt+i)->liter,(pt+i)->math,(pt+i)->english,(pt+i)->total);
		//while(getchar()!='\n')
		//	continue;
	}
	fclose(in);

	//sort 
	printf("please choose the key to sort\n:");
	//while((option=getchar())!='*')
	scanf("%c",&option);
	{
		//if( option=='\n')
		//	continue;
		if(islower(option))
			switch(option)
			{
			case 't':
				{
				for(i=0;i<Maxsize-1;i++)
				{
					flag=0;
					for(j=0;j<Maxsize-1-i;j++)
					if((pt+j)->total <= (pt+j+1)->total)
					{
						*temp=*(pt+j);
						*(pt+j)=*(pt+j+1);
						*(pt+j+1)=*temp;
						flag=1;
					}
					}
					//if(flag==0)
					//	break;
				}
				(pt)->rank=1;
				for(j=1;j<Maxsize;j++)
				{
					if(((pt+j)->total) == ((pt+j-1)->total))
						(pt+j)->rank = (pt+j-1)->rank;
					else
						(pt+j)->rank=j+1;
				}


			}

	}


	for(i=0;i<Maxsize;i++)
		printf("rank: %4d; name: %10s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt+i)->rank,(pt+i)->name,(pt+i)->liter,(pt+i)->math,(pt+i)->english,(pt+i)->total);


	free(pt);
	free(temp);
	return 0;
}

char *s_get(char *st, int n)
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

