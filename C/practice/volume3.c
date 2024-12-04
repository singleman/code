#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

struct data{
        double BaseRadius;
        double BaseHeight;
        double ColumnRadius;
        double ColumnOut;

        double Center,CoMin,CoMax; //上圆柱参数
        double SectorMin,SectorMax;
};
struct integration{
        double Xmin,Xmax;
        double Ymin,Ymax;
        double Zmin,Zmax;//扇形界限，区分6种情况
        double VolBase,VolCol;
        int sign;
};

void InitPara(struct data *pst)
{
    printf("please input the BaseRadius:"); //input the four parameter
    scanf("%lf",&pst->BaseRadius);
    printf("please input the BaseHeight:");
    scanf("%lf",&pst->BaseHeight);
    printf("please input the ColumnRadius:");
    scanf("%lf",&pst->ColumnRadius);
    printf("please input the ColumnOut:");
    scanf("%lf",&pst->ColumnOut);

    pst->Center=pst->BaseRadius+pst->ColumnOut-pst->ColumnRadius; //上圆柱参数
    pst->CoMin=pst->Center-pst->ColumnRadius;
    pst->CoMax=pst->Center+pst->ColumnRadius;

    pst->SectorMax=pst->BaseRadius;                             //扇形上下限
    pst->SectorMin=pst->BaseRadius-pst->BaseHeight;
}

void FilePara(struct data *pst,FILE **fp)////????
{
	while(fscanf(*fp,"%lf",&pst->BaseRadius)!=1){
		printf("illegal input,please check out data.txt!\n");
		exit(1);
	}
    while(fscanf(*fp,"%lf",&pst->BaseHeight)!=1){
		printf("illegal input,please check out data.txt!\n");
		exit(1);
	}
    while(fscanf(*fp,"%lf",&pst->ColumnRadius)!=1){
		printf("illegal input,please check out data.txt!\n");
		exit(1);
	}
    while(fscanf(*fp,"%lf",&pst->ColumnOut)!=1){
		printf("illegal input,please check out data.txt!\n");
		exit(1);
	}
	
    pst->Center=pst->BaseRadius+pst->ColumnOut-pst->ColumnRadius; //上圆柱参数
    pst->CoMin=pst->Center-pst->ColumnRadius;
    pst->CoMax=pst->Center+pst->ColumnRadius;

    pst->SectorMax=pst->BaseRadius;                             //扇形上下限
    pst->SectorMin=pst->BaseRadius-pst->BaseHeight;
	
}
double SectorArea(double radius,double distance)	//弧顶面积=扇形面积-三角形面积 
{
    double CircleArea;
    CircleArea=acos(distance/radius)*pow(radius,2)-distance*sqrt(pow(radius,2)-pow(distance,2));
    return CircleArea;
}

double Pytha(double hypo,double ang)		//勾股定理 
{
    return sqrt(hypo*hypo-ang*ang);
}

void ProcessPara(struct data *pst,struct integration *i)
{
    double disH,disL;               //上圆柱下沉的位置，和扇形上下限的距离
    double HighCol,HighBase;        //圆柱体的高
    HighCol=2*Pytha(pst->BaseRadius,pst->BaseRadius-pst->BaseHeight); //定值？

    if(pst->Center>=pst->SectorMax){    //情况1：圆心高于扇形(注意0有没有影响) 
        disH=pst->Center-pst->SectorMax;
        disL=pst->Center-pst->SectorMin;
        
		if(pst->CoMin>=pst->SectorMin){					//1A圆柱沉入扇形区域 
            i->Ymin=pst->CoMin;							//积分范围 
            i->Ymax=pst->SectorMax;
            i->Zmin=0;
            i->Zmax=Pytha(pst->ColumnRadius,disH);
            i->Xmin=0;
            i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
            i->VolCol=M_PI*pow(pst->ColumnRadius,2)*HighCol;	//体积 
            HighBase=2*i->Zmax;
            i->VolBase=SectorArea(pst->BaseRadius,i->Ymin)*HighBase;
            i->sign=1;
        }
        else{										//1B圆柱沉入底座 
			i->Ymin=pst->SectorMin;
			i->Ymax=pst->SectorMax;
			i->Zmin=Pytha(pst->ColumnRadius,disL);
			i->Zmax=Pytha(pst->ColumnRadius,disH);
			i->Xmin=0;
			i->Xmax=Pytha(pst->BaseRadius,i->Ymin); 
			i->VolCol=(M_PI*pow(pst->ColumnRadius,2)-SectorArea(pst->ColumnRadius,disL))*HighCol;
			HighBase=2*i->Zmax;
			i->VolBase=SectorArea(pst->BaseRadius,i->Ymin)*HighBase;
			i->sign=2;
		} 
    }
    else if(pst->Center<=pst->SectorMin){	//情况2：圆心沉入底座
	 		disH=pst->SectorMax-pst->Center;
        	disL=pst->SectorMin-pst->Center;
			 
			if(pst->CoMax<=pst->SectorMax){					//2A圆柱低于扇形区域 
	            i->Ymin=pst->SectorMin;							//积分范围 
	            i->Ymax=pst->CoMax;
	            i->Zmin=0;
	            i->Zmax=Pytha(pst->ColumnRadius,disL);
	            i->Xmin=0;
	            i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
	            i->VolCol=SectorArea(pst->ColumnRadius,disL)*HighCol;	//体积 
	            HighBase=2*i->Zmax;
	            i->VolBase=(SectorArea(pst->BaseRadius,i->Ymin)-SectorArea(pst->BaseRadius,i->Ymax))*HighBase;
	            i->sign=3;
	        }
	        else{										//2B圆柱高于扇形 
				i->Ymin=pst->SectorMin;
				i->Ymax=pst->SectorMax;
				i->Zmin=Pytha(pst->ColumnRadius,disH);
				i->Zmax=Pytha(pst->ColumnRadius,disL);
				i->Xmin=0;
				i->Xmax=Pytha(pst->BaseRadius,i->Ymin); 
				i->VolCol=SectorArea(pst->ColumnRadius,disL)*HighCol;
				HighBase=2*i->Zmax;
				i->VolBase=SectorArea(pst->BaseRadius,i->Ymin)*HighBase;
				i->sign=4;
			} 

    }
    else{
		disH=pst->SectorMax-pst->Center;
        disL=pst->Center-pst->SectorMin;								//情况3：圆心位于扇形区域 
		if((pst->CoMax>pst->SectorMax)&&(pst->CoMin<pst->SectorMin))	//3A:圆柱覆盖三个区域
		{
			i->Ymin=pst->SectorMin;
			i->Ymax=pst->SectorMax;
			if(disH>disL)
				i->Zmin=Pytha(pst->ColumnRadius,disH);
			else
				i->Zmin=Pytha(pst->ColumnRadius,disL);
			i->Zmax=pst->ColumnRadius;
			i->Xmin=0;
			i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
			i->VolCol=(M_PI*pow(pst->ColumnRadius,2)-SectorArea(pst->ColumnRadius,disL))*HighCol;
			HighBase=2*i->Zmax;
			i->VolBase=SectorArea(pst->BaseRadius,i->Ymin)*HighBase;
			i->sign=5;
		} 
		if((pst->CoMax<=pst->SectorMax)&&(pst->CoMin>=pst->SectorMin))	//3B:圆柱位于扇形区域
		{
			i->Ymin=pst->CoMin;
			i->Ymax=pst->CoMax;
			i->Zmin=0;
			i->Zmax=pst->ColumnRadius;
			i->Xmin=0;
			i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
			i->VolCol=M_PI*pow(pst->ColumnRadius,2)*HighCol;
			HighBase=2*i->Zmax;
			i->VolBase=(SectorArea(pst->BaseRadius,i->Ymin)-SectorArea(pst->BaseRadius,i->Ymax))*HighBase;
			i->sign=6;
		} 
		if((pst->CoMax<=pst->SectorMax)&&(pst->CoMin<pst->SectorMin))	//3C:圆柱覆盖下方两个区域
		{
			i->Ymin=pst->SectorMin;
			i->Ymax=pst->CoMax;
			i->Zmin=0;
			i->Zmax=pst->ColumnRadius;
			i->Xmin=0;
			i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
			i->VolCol=(M_PI*pow(pst->ColumnRadius,2)-SectorArea(pst->ColumnRadius,disL))*HighCol;
			HighBase=2*i->Zmax;
			i->VolBase=(SectorArea(pst->BaseRadius,i->Ymin)-SectorArea(pst->BaseRadius,i->Ymax))*HighBase;
			i->sign=7;
		}
		if((pst->CoMax>pst->SectorMax)&&(pst->CoMin>=pst->SectorMin))	//3D:圆柱覆盖上方两个区域
		{
			i->Ymin=pst->CoMin;
			i->Ymax=pst->SectorMax;
			i->Zmin=0;
			i->Zmax=pst->ColumnRadius;
			i->Xmin=0;
			i->Xmax=Pytha(pst->BaseRadius,i->Ymin);
			i->VolCol=M_PI*pow(pst->ColumnRadius,2)*HighCol;
			HighBase=2*i->Zmax;
			i->VolBase=SectorArea(pst->BaseRadius,i->Ymin)*HighBase;
			i->sign=8;
		}
    }

}



int base(double x,double y,double radius)   //在下底座扇形内部
{
    if(x*x+y*y<radius*radius)
        return 1;
    else
        return 0;
}
int column(double y,double z,struct data *pst) //在上底座圆柱外面
{
    if((y-pst->Center)*(y-pst->Center)+z*z>=(pst->ColumnRadius)*(pst->ColumnRadius))
        return 1;
    else
        return 0;
}

int main()
{
	time_t first,second;
	double x,y,z,step,volume;
	FILE *fp,*dp;
	char c;
	int row=0; 
	int i;
		
    struct data L;
    struct integration M;  
    
    printf("which way do you want to input the data:\n");
    printf("\t1.Manual.\n");
    printf("\t2.FIle:data.txt(BaseRadius BaseHeight ColumnRadius ColumnOut)\n");
    scanf("%d",&i);
    fp=fopen("result3.txt","a");
    if(i==1){
		InitPara(&L); //手动输入数据
		ProcessPara(&L,&M);
		fprintf(fp,"The BaseRadius=%f\nThe BaseHeight=%f\nThe ColumnRadius=%f\nThe ColumnOut=%f\n",L.BaseRadius,L.BaseHeight,L.ColumnRadius,L.ColumnOut);
		for(step=0.1;step>0.0001;step=step/10)
		{
				volume=0;
				first=time(NULL);
			    for(x=M.Xmin;x<M.Xmax;x=x+step)
			    {
			        for(z=M.Zmin;z<M.Zmax;z=z+step)
			        {
			             for(y=M.Ymin;y<M.Ymax;y=y+step)
			                {
			                	if(base(x,y,L.BaseRadius)&&column(y,z,&L)){
			                		volume=volume+pow(step,3);
			                	}
			                }
			        }
			    }
			    second=time(NULL);
		      	printf("step= %lf the volumn is %f,time is %d\n",step,M.VolCol-(M.VolBase-4*volume),second-first);
		      	fprintf(fp,"\tstep= %lf the volume is %f,time is %d\n",step,M.VolCol-(M.VolBase-4*volume),second-first);
		}
	}
	else{
	    
	    dp=fopen("data.txt","r");
	     
	    while((c=fgetc(dp))!=EOF){
	    	if(c=='\n')
	    		row++;
		} 
		rewind(dp); 
		for(i=0;i<row+1;i++){
			FilePara(&L,&dp); 
	    	ProcessPara(&L,&M); 
	
		    fprintf(fp,"The BaseRadius=%f\nThe BaseHeight=%f\nThe ColumnRadius=%f\nThe ColumnOut=%f\n",L.BaseRadius,L.BaseHeight,L.ColumnRadius,L.ColumnOut);
		    fprintf(fp,"M.sign=%d\n",M.sign);
		    for(step=0.1;step>0.0001;step=step/10)
			{
				volume=0;
				first=time(NULL);
			    for(x=M.Xmin;x<M.Xmax;x=x+step)
			    {
			        for(z=M.Zmin;z<M.Zmax;z=z+step)
			        {
			             for(y=M.Ymin;y<M.Ymax;y=y+step)
			                {
			                	if(base(x,y,L.BaseRadius)&&column(y,z,&L)){
			                		volume=volume+pow(step,3);
								}
			                }
			        }
			    }
			    second=time(NULL);
		    	fprintf(fp,"\tstep= %lf the volume is %f,time is %d\n",step,M.VolCol-(M.VolBase-4*volume),second-first);
		    	printf("step= %lf the volumn is %f,time is %d\n",step,M.VolCol-(M.VolBase-4*volume),second-first);
			}
		}
	    
		fclose(fp);
	}
	fclose(dp);
    return 0;
}
