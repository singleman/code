#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int bouncingBall( double h, double bounce, double window);

int main()
{
	int a;
	double h,bounce,window;
	a = bouncingBall( h, bounce, window);
	return 0;
}

int bouncingBall( double h, double bounce, double window)
{
	printf("Please input the heigh of the building:\n");
	while( scanf("%lf",&h) != 1 || h < 0 )
	{
		printf("make sure you have input the right data:\n");
		while(getchar() != '\n')
			continue;
	}
	printf("Please input the parameter of the bounce:\n");
	while( scanf("%lf",&bounce) != 1 || bounce < 0 || bounce > 1)
	{
		printf("make sure you have input the right data:\n");
		while(getchar() != '\n')
			continue;
	}
	printf("Please input the heigh of the window:\n");
	while( scanf("%lf",&window) != 1 || window < 0 || window >= h )
	{
		printf("make sure you have input the right data:\n");
		while(getchar() != '\n')
			continue;
	}
	printf(" h = %f , bounce = %f , window = %f \n",h, bounce, window);

	int times=0;
	double temp;
	temp = h;
	
	while( h >= window)
	{
		h = h * bounce;
		if( h > window )
			times=+1;	
	}
	printf(" h = %f , bounce = %f , window = %f ,result is %d\n",temp, bounce, window, times);
	return times;
}
