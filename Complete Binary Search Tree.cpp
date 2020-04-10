#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxN 10005

int Compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int TreeGetleftNum(int n)
{
    int h, x, leftNum;
    for (h = 0; (pow(2, h) - 1) <= n; h++)
        ;
    x = n - (pow(2, h - 1) - 1);
    x = x < (pow(2, h - 2)) ? x : (pow(2, h - 2));
    leftNum = x + (pow(2, h - 2) - 1);
    return leftNum;
}

void Solve(int array[], int left, int right, int tree[], int root)
{
    int n, leftNum, leftRoot, rightRoot;
    n = right - left + 1;
    if (!n)
        return;
    leftNum = TreeGetleftNum(n);
    tree[root] = array[left + leftNum];
    leftRoot = root * 2;
    rightRoot = leftRoot + 1;
    Solve(array, left, left + leftNum - 1, tree, leftRoot);
    Solve(array, left + leftNum + 1, right, tree, rightRoot);
}

int main()
{
    int array[MaxN] = {0};
    int tree[MaxN] = {0};
    int n, temp = 0, flag = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &array[i]);

    // qsort(&array[1], n, sizeof(int), Compare);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    Solve(array, 1, n, tree, 1);

    for (int i = 1; i <= n; i++)
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d", tree[i]);
    }

    return 0;
}
