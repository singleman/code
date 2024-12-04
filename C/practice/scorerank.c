#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define LEN 40

#define STRST struct student
#define STRTS struct totalstudent


char *s_get(char *st, int n);

struct student{
	char name[LEN];
	int liter,math,english,total,rank;
};

struct totalstudent{
	struct student *st;
	int size;
	int Maxsize;
};

void eatline()
{
	while(getchar()!='\n')
		continue;
}

void Init(STRTS *pt,int ms)
{
	if(ms<0)
	{
		printf("illegal value of Maxsize!\n");
		exit(1);
	}
	pt->Maxsize=ms;
	pt->st=malloc(ms*sizeof(STRST));		//Waste space;
	pt->size=0;
}

void Clear(STRTS *pt)
{
	if(pt->st != NULL)
		free(pt->st);
	pt->size=0;
	pt->Maxsize=0;
}

void againMalloc(STRTS *pt,int size)
{
	STRST *ptemp=realloc(pt->st,2*size*sizeof(struct student));
	if(!ptemp)
	{
		printf("no more space to use!\n");
		exit(1);	
	}
	pt->st=ptemp;
	pt->Maxsize=2*pt->Maxsize;
}

void scrinput(STRTS *pt)   //screen input
{
	int count=0;

	printf("please input the student name:\n");	
	while(s_get((pt->st[count]).name,LEN)!= NULL)
	{
		printf("please input the score:\n");	
		scanf("%d %d %d",&((pt->st[count]).liter),&((pt->st[count]).math),&((pt->st[count]).english));
		(pt->st[count]).total=(pt->st[count]).liter +(pt->st[count]).math+(pt->st[count]).english;
		count+=1;
		if(count==pt->Maxsize)
			againMalloc(pt,count);
			
		printf("name: %4s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt->st[count]).name,(pt->st[count]).liter,(pt->st[count]).math,(pt->st[count]).english,(pt->st[count]).total);
		while(getchar()!='\n')
			continue;
	}
	pt->size=count;
}

void fileinput(STRTS *pt)
{
	FILE *in;
	int count=0;
	in = fopen ("score","r");
	while((fscanf(in,"%s %d %d %d\n",(pt->st[count]).name,&((pt->st[count]).liter),&((pt->st[count]).math),&((pt->st[count]).english)))!=EOF)
	{
		(pt->st[count]).total=(pt->st[count]).liter +(pt->st[count]).math+(pt->st[count]).english;
		count+=1;
		if(count==pt->Maxsize)
			againMalloc(pt,count);
		//printf("name: %4s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt->st[count]).name,(pt->st[count]).liter,(pt->st[count]).math,(pt->st[count]).english,(pt->st[count]).total);
		//printf("name: %4s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt+i)->name,(pt+i)->liter,(pt+i)->math,(pt+i)->english,(pt+i)->total);
		//while(getchar()!='\n')
		//	continue;
	}
	fclose(in);
	pt->size=count;
}

void sort(STRTS *pt)
{
	char option;
	int count,i,j,flag;
	STRST temp;
	printf("please choose the key to sort:(both uppercase and lowercase is OK)\n");
	puts("t)total	 	l)liter");
	puts("m)math		e)english");
	scanf("%c",&option);
	//option=getchar();
	eatline();
	while(strchr("tlme",option)==NULL)
	{
		puts("please enter t l m e");
		scanf("%c",&option);
		//option = getchar();
		eatline();
	}
	if(islower(option))
		switch(option)
		{
		case 't':
			{
			for(i=0;i<pt->Maxsize-1;i++)
			{
				flag=0;
				for(j=0;j<pt->Maxsize-1-i;j++)
				if((pt->st[j]).total < (pt->st[j+1]).total)
				{
					temp=(pt->st[j]);
					(pt->st[j])=(pt->st[j+1]);
					(pt->st[j+1])=temp;
					flag=1;
				}
			}
			if(flag==0)
				break;
			}
		case 'l':
			{
			for(i=0;i<pt->Maxsize-1;i++)
			{
				flag=0;
				for(j=0;j<pt->Maxsize-1-i;j++)
				if((pt->st[j]).liter < (pt->st[j+1]).liter)
				{
					temp=(pt->st[j]);
					(pt->st[j])=(pt->st[j+1]);
					(pt->st[j+1])=temp;
					flag=1;
				}
			}
			if(flag==0)
				break;
			}
		case 'm':
			{
			for(i=0;i<pt->Maxsize-1;i++)
			{
				flag=0;
				for(j=0;j<pt->Maxsize-1-i;j++)
				if((pt->st[j]).math < (pt->st[j+1]).math)
				{
					temp=(pt->st[j]);
					(pt->st[j])=(pt->st[j+1]);
					(pt->st[j+1])=temp;
					flag=1;
				}
			}
			if(flag==0)
				break;
			}
		case 'e':
			{
			for(i=0;i<pt->Maxsize-1;i++)
			{
				flag=0;
				for(j=0;j<pt->Maxsize-1-i;j++)
				if((pt->st[j]).english < (pt->st[j+1]).english)
				{
					temp=(pt->st[j]);
					(pt->st[j])=(pt->st[j+1]);
					(pt->st[j+1])=temp;
					flag=1;
				}
			}
			if(flag==0)
				break;
			}
		}
}

void rank(STRTS *pt)
{
	int i,j;

	(pt->st[0]).rank=1;
	for(j=1;j<pt->size;j++)
	{
		if(((pt->st[j]).total) == ((pt->st[j-1]).total))
			(pt->st[j]).rank = (pt->st[j-1]).rank;
		else
			(pt->st[j]).rank=j+1;
	}
	for(i=0;i<pt->size;i++)
		printf("rank: %4d; name: %15s; liter: %3d; math: %3d; english: %3d; total: %3d\n",(pt->st[i]).rank,(pt->st[i]).name,(pt->st[i]).liter,(pt->st[i]).math,(pt->st[i]).english,(pt->st[i]).total);
}


int main()
{
	struct totalstudent pt;
	Init(&pt,2);
	fileinput(&pt);
	sort(&pt);
	rank(&pt);
	Clear(&pt);
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

