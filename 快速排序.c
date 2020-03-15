#include <stdio.h>
#include <string.h>

void quick_sort(int array[],int left,int right)
{
	int i=left,j=right;
	int temp,mid;

	mid=array[(left+right)/2];

	while(i<=j)
	{
		while(array[i]<mid)
		{
			i++;
		}
		while(array[j]>mid)
		{
			j--;
		}

		if(i<=j)
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j--;
		}
	}

	if(j>left)
	{
		quick_sort(array,left,j);
	}

	if(i<right)
	{
		quick_sort(array,i,right);
	}

}

int main()
{
	int array[]= {1,11,15,48,79,88,55,66,11};
	int i,length;

	length=sizeof(array)/sizeof(array[0]);

	quick_sort(array,0,length-1);

	printf("Result:");

	for(i=0; i<length; i++)
	{
		printf("%d ",array[i]);
	}

	return 0;
}

