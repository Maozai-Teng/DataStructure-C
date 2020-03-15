#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "iostream"
using namespace std;


int swap1(int *pleft,int *pright)
{
	(*pleft)++;
	(*pright)--;
	return 0;
}

int swap2(int **ppleft,int **ppright)
{
	(*ppleft)++;
	(*ppright)--;
	return 0;
}

int main(void)
{
	int a[]={-4,-3,-2,-1,0,1,2,3,4};
	
	int left=a[0];
	int right=a[8];
	
	int *pleft=&a[0];
	int *pright=&a[8];
	
	int **ppleft=&pleft;
	int **ppright=&pright;
	
	for(int i=0;i<8;i++)
	{
		printf("%d %d\n",*pleft,*pright);
		swap2(&pleft,&pright);
		printf("%d %d\n\n",*pleft,*pright);
	}
	
	
	return 0;
}
