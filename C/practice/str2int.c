#include<stdio.h>
<<<<<<< HEAD
=======

>>>>>>> bc28970cc2a4d2c6b7c1aec5de8117d4db538448
#define LEN 41

int main()
{
    char str[LEN];
    char *ptr;
<<<<<<< HEAD
    int digit[LEN]={0};
    int i,j;
    int key=0;
=======
    int digit=0;
    int i,j,k,key;
>>>>>>> bc28970cc2a4d2c6b7c1aec5de8117d4db538448

    printf("please input a string:\n");
    ptr = fgets(str,LEN,stdin);

<<<<<<< HEAD
    i=0;
    while(*ptr != '\0')
=======
    i=0;j=0;k=0;
    key=1;
    while(ptr != NULL)
>>>>>>> bc28970cc2a4d2c6b7c1aec5de8117d4db538448
    {
         if((*ptr < '0') || (*ptr > '9'))
        {

            ptr++;
<<<<<<< HEAD
	    key=0;
            continue;
        }
	if(key==0)
		i++;
        digit[i]=digit[i]*10+(*ptr-'0');
	key=1;
        ptr++;
    }

    j=i;
    for(i=1;i<=j;i++)
	  printf("%d number is %d\n",i,digit[i]);
=======
            key = 0;
            continue;
        }
        digit=digit*10+(*ptr-'0');
        ptr++;


    }
    printf("the number is %d\n",digit);

>>>>>>> bc28970cc2a4d2c6b7c1aec5de8117d4db538448

    return 0;
}
