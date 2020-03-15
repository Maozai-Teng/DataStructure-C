#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

clock_t start,stop;
double duration;
const int MAXN=10,MAXK=1e6;

double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for(i=1; i<=n; i++)
	{
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double f2(int n,double a[],double x)
{
	int i;
	double p=a[n];
	for(i=n; i>0; i--)
	{
		p=p*x+a[n-1];
	}
	return p;
}

int main(void)
{
	int i;
	double a[MAXN]={0};
	for(i=0;i<MAXN;i++)
	{
		a[i]=(double)i;
	}
	
	start=clock();
	for(i=0;i<MAXK;i++)
	{
		f1(MAXN-1,a,1.1);
	}
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK/MAXK;
	printf("ticks1=%f\n",(double)(stop-start));
	printf("duration=%6.2e\n",duration);
	
	start=clock();
	for(i=0;i<MAXK;i++)
	{
		f2(MAXN-1,a,1.1);
	}
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK/MAXK;
	printf("ticks1=%f\n",(double)(stop-start));
	printf("duration=%6.2e\n",duration);
	
	return 0;
}
