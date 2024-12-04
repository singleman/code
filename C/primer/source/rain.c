#include<stdio.h>
#define YEAR 5
#define MONTH 12
int main(void)
{
	const float rain[YEAR][MONTH]={
		{4.3,3.2,23,23,2,3,23,12,32.2,34,23,23},
		{8.5,9.3,2.3,2.3,21.2,1.2,3.4,9.3,23.2,2,2,3},
		{8.5,9.3,2.3,2.3,21.2,1.2,3.4,9.3,23.2,2,2,3},
		{8.5,9.3,2.3,2.3,21.2,1.2,3.4,9.3,23.2,2,2,3},
		{8.5,9.3,2.3,2.3,21.2,1.2,3.4,9.3,23.2,2,2,3},
	};
	int year,month;
	float subtot,total;

	printf("YEAR RAINFALL (inches)\n");
	for(year=0,total=0;year<YEAR;year++)
	{
		for(month=0,subtot-0;month<MONTH;month++)
			subtot +=rain[year][month];
		printf("%5d %15.1f\n",2010+year,subtot);
		total +=subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n",total/YEAR);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	
	for(month=0;month<MONTH;month++)
	{
		for(year=0,subtot=0;year<YEAR;year++)
			subtot+= rain[year][month];
		printf("%4.1f ",subtot/YEAR);
	}
	printf("\n");
	return 0;
}
