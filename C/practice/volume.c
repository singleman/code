#include<stdio.h>
#include<math.h>

struct para{
        float BaseRadius;
        float BaseHeight;
        float VolumnRadius;
        float VolumnOut;
        float VolumnCenter;
        float Xrange;
        float Yrange,Yinit;
        float Zrange;
};
void InitPara(struct para *pst)  //input the four parameter
{
    printf("please input the BaseRadius:");
    scanf("%f",&pst->BaseRadius);
    printf("please input the BaseHeight:");
    scanf("%f",&pst->BaseHeight);
    printf("please input the VolumnRadius:");
    scanf("%f",&pst->VolumnRadius);
    printf("please input the VolumnOut:");
    scanf("%f",&pst->VolumnOut);
    pst->VolumnCenter=pst->BaseRadius+pst->VolumnOut-pst->VolumnRadius;
    pst->Xrange = sqrt(pst->BaseRadius*pst->BaseRadius-(pst->BaseRadius-pst->BaseHeight)*(pst->BaseRadius-pst->BaseHeight));
    pst->Yrange = pst->BaseRadius+pst->VolumnOut;
    pst->Yinit = pst->BaseRadius-pst->BaseHeight;
    pst->Zrange = pst->VolumnRadius;

}

int base(float x,float y,float radius)
{
    if(x*x+y*y>radius*radius)
        return 1;
    else
        return 0;
}
int column(float y,float z,struct para *pst)
{
    if((y-pst->VolumnCenter)*(y-pst->VolumnCenter)+z*z<(pst->VolumnRadius)*(pst->VolumnRadius))
        return 1;
    else
        return 0;
}

int main()
{
    struct para L;
    InitPara(&L);
    float x,y,z,step,result;
    result=0;
    printf("please input the step of Microelement:");
    scanf("%d",&step);
    for(x=0;x<L.Xrange;x=x+step)
    {
        for(z=0;z<L.Zrange;z=z+step)
        {
             for(y=L.Yinit;y<L.Yrange;y=y+step)
                {
                    if(base(x,y,L.BaseRadius)&&column(y,z,&L))
                        result=result+step*step*step;
                    //printf("1");
                }
        }
    }
    printf("the volumn is %f\n",4*result);
    return 0;
}
