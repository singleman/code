#include<stdio.h>
#include<time.h>

int main()
{
    time_t first;    //定义变量
    struct tm *local;       //tm结构体变量
    first=time(NULL);       //取得当前时间，以秒计算time()函数
    local=localtime(&first);//把以秒计算的时间转化为正常的时间并存储到结构体当中
    printf("以秒为单位的时间：%d\n",first);
    printf("真实时间：%d:%d:%d:%d:%d\n",local->tm_year+1900,local->tm_mon,local->tm_mday,local->tm_hour,local->tm_min);
    return 0;
}
