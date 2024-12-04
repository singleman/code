#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	FILE *fp;
	float coe[3];
	float result1,result2,delta;


	fp = fopen("coefficient","r");
	while(!feof(fp))
	{
		fscanf(fp," %f %f %f\n",&coe[0],&coe[1],&coe[2]);
		if(coe[0]==0)
		{
			if(coe[1]==0)
				printf("%.1fx^2+%.1fx+%.1f has countless result\n",coe[0],coe[1],coe[2]);
			else
			{
				result1 = (-1)*coe[2]/coe[1];
				printf("%.1fx^2+%.1fx+%.1f has one result x=%.2f\n",coe[0],coe[1],coe[2],result1);
			}
		}
		else
		{
			delta=coe[1]*coe[1]-4*coe[0]*coe[2];
			if(delta > 0)
			{
				result1=((-1)*coe[1]+sqrt(delta))/2*coe[0];
				result2=((-1)*coe[1]-sqrt(delta))/2*coe[0];
				printf("%.1fx^2+%.1fx+%.1f has two result x1=%f,x2=%f\n",coe[0],coe[1],coe[2],result1,result2);
			}
			else
			{
				if(delta=0)
				{
					result1=((-1)*coe[1])/2*coe[0];
					printf("%.1fx^2+%.1fx+%.1f has one result x1=%f\n",coe[0],coe[1],coe[2],result1);
				}
				else
					printf("%.1fx^2+%.1fx+%.1f has no result \n",coe[0],coe[1],coe[2]);
			}		
		}

				
	}
	fclose(fp);
	return 0;
}

