#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "iostream"
using namespace std;

int MaxSubseqSum4(int a[],int n,int **ppleft,int **ppright)
{
	int max=-1,sum=0;
	int *tpleft=*ppleft;
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
		if(sum<0)
		{
			sum=0;
			tpleft=&a[i+1];
		}
		else if(sum>max)
		{
			max=sum;
			*ppleft=tpleft;
			*ppright=&a[i];
		}
	}
	if(max<0)
	{
		max=0;
	}
	return max;
}

int main(void)
{
	int i,n;
	cin>>n;
	int a[100000+1]= {0};
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}

	int *pleft=&a[0];
	int *pright=&a[n-1];
	int max=MaxSubseqSum4(a,n,&pleft,&pright);

	printf("%d %d %d\n",max,*pleft,*pright);

	return 0;
}
