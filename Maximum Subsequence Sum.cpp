#include <stdio.h>
#include <stdlib.h>

int MaxSubSum(int a[], int n, int *first, int *last)
{
    int sum = 0, max = -1, mark = 0;
    *first = 0;
    *last = n - 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
        {
            sum = 0;
            mark = i + 1;
        }

        else if (sum > max)
        {
            max = sum;
            *first = mark;
            *last = i;
        }
    }
    if (max < 0)
        max = 0;
    return max;
}

int main()
{
    int n, sum, first, last;
    int a[100000 + 1] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sum = MaxSubSum(a, n, &first, &last);
    printf("%d %d %d\n", sum, a[first], a[last]);

    return 0;
}
