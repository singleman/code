/*班级：2014级机制本15班   学号：201433428   开发者：徐冬爽   
开发时间：2017年5月   开发地点：郑州科技学院
题目：以2007年12月的利率为标准，按以下方式存款：
1、一次存五年期 2、先存2年期，到期后将本息再存3年期 3、先存3年期，到期后将本息再存2年期 4、先存1年期，到期后将本息再存1年期，连续存5次 5、存活期存款，活期利息每一年度结算一次*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void menu();                             //指定菜单函数
int main()
{
	int x,j=1;
	float p;
	double r5,r3,r2,r1,r0,p1,p2,p3,p4,p5;
	char yesno;
	                                     //五种存款方案利率
	r5=0.0585;
	r3=0.054;
	r2=0.0468;
	r1=0.0414;
	r0=0.0072;
	
	menu();                              //调用菜单函数

	do{                                  //循环计算函数体
		fflush(stdin);                   //清理缓冲区或计算错误
      f:printf("请输入存款方式：");
        scanf("%d",&x);
        printf("请输入存款金额：");
        scanf("%f",&p);

    switch(x)                             //判断选择计算函数
	{
    case 1:p1=p*(1+r5*5);printf("p1=%f\n",p1);break;            //一次存五年期
    case 2:p2=p*(1+r2*2)*(1+r3*3);printf("p2=%f\n",p2);break;   //先存2年期，到期后将本息再存3年期
    case 3:p3=p*(1+r3*3)*(1+r2*2);printf("p3=%f\n",p3);break;   //先存3年期，到期后将本息再存2年期
    case 4:p4=p*pow(1+r1,5);printf("p4=%f\n",p4);break;         //先存1年期，到期后将本息再存1年期，连续存5次
    case 5:p5=p*pow(1+r0/4,4*5);printf("p5=%f\n",p5);           //存活期存款，活期利息每一年度结算一次
	}

    printf("是否继续（y/n）？\n\n");                              //循环判断
    getchar();
    scanf("%c",&yesno);
    if(yesno=='n'||yesno=='N')j=0;
    else if(yesno=='y'||yesno=='Y'){x=-1;p=-1;}
    else {printf("输入有误，请重新输入！\n");goto f;
	}

}
while(j);        //循环指令
return 0;

}

//***************———子函数调用———***************
    
void menu()      //主菜单函数
{
printf("\t班级：2014级机制本15班    学号：201433428     开发者：徐冬爽\n");
printf("\t开发时间：2017年5月   开发地点：郑州科技学院   版本：第二版\n\n");
printf("\t\t\t\t银行存款本息和计算系统\n\n");
printf("\t 存款方案选择如下：            \n\n");
printf("\t 1、一次存五年期;\n");
printf("\t 2、先存2年期,到期后将本息再存3年期;\n");
printf("\t 3、先存3年期,到期后将本息再存2年期;\n");
printf("\t 4、先存1年期,到期后将本息再存1年期，连续存5次;\n");
printf("\t 5、存活期存款,活期利息每一年度结算一次;\n\n");

}