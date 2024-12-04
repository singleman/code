#include<stdio.h>

#define LEN 20

struct names{
	char firstname[LEN];
	char middlename[LEN];
	char lastname[LEN];
};

struct information{
	int number;
	struct names name;
};

void display(struct information *pt);
int main()
{
	struct information person[2]={
		{12345,{"ming","","su"}},
		{23456,{"hui","f","feng"}}
	};
	display(person);
	return 0;
}

void display(struct information pt[2])
{
	int i;
	for(i=0;i<2;i++)
		if(pt[i].name.middlename[0]!='\0')
			printf("%s,	%s	%c.	--	%d\n",pt[i].name.firstname,pt[i].name.lastname,pt[i].name.middlename[0],pt[i].number);
		else
			
			printf("%s,	%s	--	%d\n",pt[i].name.firstname,pt[i].name.lastname,pt[i].number);

}
