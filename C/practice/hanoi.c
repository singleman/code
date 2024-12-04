#include<stdio.h>
int i=0;
void move(int n, char from,char to)
{
    printf("%d.move the %d plater from %c---->%c\n",i++,n,from,to);
}

void hanoi(int n,char from,char depend_on,char to)
{
    if(n==1)
        move(1,from,to);
    else
    {
        hanoi(n-1,from,depend_on,to);
        move(n,from,depend_on);
        hanoi(n-1,to,depend_on,from);
        move(n,depend_on,to);
        hanoi(n-1,from,depend_on,to);
    }
}

int main()
{
    printf("input the number of plates:\n");
    int n;
    while(scanf("%d",&n)==1)
    {
        char x='A',y='B',z='C';
        printf("you can finish like this:\n");
        hanoi(n,x,y,z);
        printf("input again\n");
    }

    return 0;
}
