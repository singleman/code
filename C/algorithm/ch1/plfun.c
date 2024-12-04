double plfun(float * cof,int n,float x)
{
	int i;
	double result;
	result=cof[n-1];
	for(i=n-2;i>-1;i--)
		result=result*x+cof[i];
	return result;
}
