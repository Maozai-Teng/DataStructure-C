#include <stdio.h>

int max(int a[],int len);

int main()
{
	int a[]= {2,25,48,7,88,9,7,55,9};
	int len=sizeof(a)/sizeof(a[0]);
	int i,temp;

	for(i=len-1;i>0;i--)
	{
		int maxid=max(a,i+1);
		temp=a[i];
		a[i]=a[maxid];
		a[maxid]=temp;
	}
	
	for(i=0;i<len;i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}

int max(int a[],int len)
{
	int maxid=0;
	int i;
	for(i=0; i<len; i++)
	{
		if(a[i]>a[maxid])
		{
			maxid=i;
		}
	}
	return maxid;
}
