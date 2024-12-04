#include<stdio.h>
#define SIZE 4
int main()
{
	int some_data[SIZE] = {1492,[3]=34};
	int i;
	printf("%2s%14s\n","i","some_data[i]");
	for(i=0;i < SIZE; i++)
		printf("%2d%14d\n",i,some_data[i]);
	printf("size of some data is %d\nsize of some data1 is %d\nsize of i is %d\n",sizeof some_data,sizeof some_data[0],sizeof i);
	return 0;
}
