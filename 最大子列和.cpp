#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "iostream"
using namespace std;

double MaxSubseqSum1(int a[], int n)
{
	double sum = 0, max = 0;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			for (k = i, sum = 0; k <= j; k++)
			{
				sum += a[k];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	return max;
}

double MaxSubseqSum2(int a[], int n)
{
	double sum, max = 0;
	int i, j;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	return max;
}

int Max3(int a, int b, int c)
{
	return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int DividAndConquer(int a[], int left, int right)
{
	if (left == right) //分到只有一个数字的时候
	{
		if (a[left] > 0)
		{
			return a[left];
		}
		else
		{
			return 0;
		}
	}

	int mid = (left + right) / 2; //从中分两部分开始递归
	int MaxLeftSum = DividAndConquer(a, left, mid);
	int MaxRightSum = DividAndConquer(a, mid + 1, right);

	int MaxLeftBorderSum = 0, LeftBorderSum = 0; //从中向左找跨界最大
	for (int i = mid; i >= left; i--)
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}

	int MaxRightBorderSum = 0, RightBorderSum = 0; //从中向右找跨界最大
	for (int i = mid + 1; i <= right; i++)
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}

	return Max3(MaxLeftBorderSum, MaxRightBorderSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int a[], int n)
{
	return DividAndConquer(a, 0, n - 1);
}

int MaxSubseqSum4(int a[], int n)
{
	int sum = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum < 0)
			sum = 0;
		else if (sum > max)
			max = sum;
	}
	return max;
}

int main(void)
{
	int n, sum;
	int a[100000 + 1] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%d\n", MaxSubseqSum1(a, n));
	printf("%d\n", MaxSubseqSum2(a, n));
	printf("%d\n", MaxSubseqSum3(a, n));
	printf("%d\n", MaxSubseqSum4(a, n));

	return 0;
}
