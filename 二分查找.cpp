#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */

Position Find(List L, ElementType X, Position left, Position right)
{
    Position mid = (left + right) / 2;
    if (left > right)
        return NotFound;
    if (X == L->Data[mid])
        return mid;

    else if (X < L->Data[mid])
        right = mid - 1;
    else if (X > L->Data[mid])
        left = mid + 1;
    return Find(L, X, left, right);
}

Position BinarySearch(List L, ElementType X) //递归做法
{
    Position left = 1;
    Position right = L->Last;

    return Find(L, X, left, right);
}

Position BinarySearch(List L, ElementType X) //循环做法
{
    Position find = NotFound;
    Position left = 1;
    Position right = L->Last;
    Position mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (X == L->Data[mid])
        {
            find = mid;
            break;
        }
        else if (X < L->Data[mid])
            right = mid - 1;
        else if (X > L->Data[mid])
            left = mid + 1;
    }
    return find;
}