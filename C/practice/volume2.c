#include<stdio.h>
#include<math.h>
#include<time.h>

struct para{
        double BaseRadius;
        double BaseHeight;
        double VolumnRadius;
        double VolumnOut;
        double VolumnCenter;
        double Xrange;
        double Yrange,Yinit;
        double Zrange;
};

void InitPara(struct para *pst)  //input the four parameter
{
    printf("please input the BaseRadius:");
    scanf("%lf",&pst->BaseRadius);
    printf("please input the BaseHeight:");
    scanf("%lf",&pst->BaseHeight);
    printf("please input the VolumnRadius:");
    scanf("%lf",&pst->VolumnRadius);
    printf("please input the VolumnOut:");
    scanf("%lf",&pst->VolumnOut);
    pst->VolumnCenter=pst->BaseRadius+pst->VolumnOut-pst->VolumnRadius;
    pst->Xrange = sqrt(pst->BaseRadius*pst->BaseRadius-(pst->BaseRadius-pst->BaseHeight)*(pst->BaseRadius-pst->BaseHeight));
    pst->Yrange = pst->BaseRadius+pst->VolumnOut;
    pst->Yinit = pst->BaseRadius-pst->BaseHeight;
    pst->Zrange = pst->VolumnRadius;

}

void FilePara(struct para *pst,FILE **fp)  //input the four parameter
{
    
    fscanf(*fp,"%lf",&pst->BaseRadius);
    fscanf(*fp,"%lf",&pst->BaseHeight);
    fscanf(*fp,"%lf",&pst->VolumnRadius);
    fscanf(*fp,"%lf",&pst->VolumnOut);
    
    pst->VolumnCenter=pst->BaseRadius+pst->VolumnOut-pst->VolumnRadius;
    pst->Xrange = sqrt(pst->BaseRadius*pst->BaseRadius-(pst->BaseRadius-pst->BaseHeight)*(pst->BaseRadius-pst->BaseHeight));
    pst->Yrange = pst->BaseRadius+pst->VolumnOut;
    pst->Yinit = pst->BaseRadius-pst->BaseHeight;
    pst->Zrange = pst->VolumnRadius;
}

int base(double x,double y,double radius)
{
    if(x*x+y*y>radius*radius)
        return 1;
    else
        return 0;
}
int column(double y,double z,struct para *pst)
{
    if((y-pst->VolumnCenter)*(y-pst->VolumnCenter)+z*z<(pst->VolumnRadius)*(pst->VolumnRadius))
        return 1;
    else
        return 0;
}

int main()
{
	time_t first,second;
	double x,y,z,step,result;
	struct para L;
	FILE *fp,*dp;
	char c;
	int row=0; 
	int i;
	fp=fopen("result2.txt","a");
    dp=fopen("data.txt","r");
     
    //InitPara(&L);
    while((c=fgetc(dp))!=EOF){
    	if(c=='\n')
    		row++;
	} 
	rewind(dp); 
	for(i=0;i<row;i++){
		FilePara(&L,&dp);
		fprintf(fp,"The BaseRadius=%f\nThe BaseHeight=%f\nThe ColumnRadius=%f\nThe ColumnOut=%f\n",L.BaseRadius,L.BaseHeight,L.VolumnRadius,L.VolumnOut);
		fprintf(fp,"M.sign=%d\n",i+1);
	    for(step=0.1;step>0.0001;step=step/10)
		{
			result=0;
			first=time(NULL);
			//local=localtime(&first);	
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
		    second=time(NULL);
		    fprintf(fp,"step= %lf the volumn is %f,time is %d\n",step,4*result,second-first);
		    printf("step= %lf the volumn is %f,time is %d\n",step,4*result,second-first);
		}
	} 
	fclose(fp);
	fclose(dp);
    return 0;
}

