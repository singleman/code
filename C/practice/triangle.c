#include<stdio.h>

int main()
{
    int i,j,k,number;
    char key;
    scanf("%c",&key);
    number=key-'A'+1;

    for(i=0;i<number;i++)
    {
        for(j=0;j<number-1-i;j++)
            printf(" ");
        for(k=0;k<2*i+1;k++)
            printf("%c",'A'+i);
        printf("\n");
    }

    for(i=number-2;i>=0;i--)
    {
        for(j=0;j<number-1-i;j++)
            printf(" ");
        for(k=0;k<2*i+1;k++)
            printf("%c",'A'+i);
        printf("\n");
    }



    return 0;
}
