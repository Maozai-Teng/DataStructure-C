#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int search(int* nums, int numsSize, int target)
{

	int left=0,right=(numsSize-1);
	int mid=-1;

	while(left<=right)
	{
		int mid=(left+right)/2;
		if(target==nums[mid])
		{
			return mid;
		}
		if(nums[mid]>=nums[left])
		{
			if(target>=nums[left]&&target<nums[mid])
			{
				right=mid-1;
			}
			else
			{
				left=mid+1;
			}
		}
		else
		{
			if(target<=nums[right]&&target>nums[mid])
			{
				left=mid+1;
			}
			else
			{
				right=mid-1;
			}
		}
	}

	return -1;
}

int main()
{
	int nums[]= {};
	int target = 0;
	int numsSize=sizeof(nums)/sizeof(nums[0]);

	int n=search(nums,numsSize,target);

	printf("%d",n);

	return 0;
}
