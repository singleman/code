// rand0.c -- produces random numbers
#include<stdio.h>
static unsigned long int next = 1; //the seed

int rand0(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
	printf("test include\n");
}
