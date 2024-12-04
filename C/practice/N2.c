#include<stdio.h>
#define LEN 20 
int main()
{
    int i,j,k,N,key,content;
    int matrix[LEN][LEN];

    //scanf("%d",&N);
    //key=0;  
    
    for(N=1;N<15;N++)
    {
	content=1;
    	key=0;
   	for(k=N-1;k>=1-N;k--)
   	{
       		key++;
      		if(k>=0)
      		{
         		switch(key%2)
          		{
          			case 1:
        				for(i=N-1,j=N-1-k;j>=0;i--,j--)
             					matrix[i][j]=content++;
					break;
           			case 0:
               				for(j=0,i=k;i<N;i++,j++)
						matrix[i][j]=content++;
               				break;
            		}
       		}
       		else
       		{
        		switch(key%2)
         		{
         			case 1:
               				for(j=N-1,i=N-1+k;i>=0;i--,j--)
                   				matrix[i][j]=content++;
               				break;
            			case 0:
               				for(i=0,j=-k;j<N;i++,j++)
                  				matrix[i][j]=content++;
               				break;
           		}
                }
   	 }
	printf("N=%d,the matrix is:\n",N);
    	for(i=0;i<N;i++)
    	{
		for(j=0;j<N;j++)
        		printf("%4d",matrix[i][j]);
      		printf("\n");
   	}
    }

    return 0;
}
