#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAXSIZE 100

typedef struct //数组线性表结构定义
{
    ElementType data[MAXSIZE];
    int last;
} ListA, *PListA;

PListA MakeEmptyListA() //建立空的数组线性表
{
    PListA ptrLA;
    ptrLA = (PListA)malloc(sizeof(ListA));
    ptrLA->last = -1;
    return ptrLA;
}

int FindListA(ElementType x, PListA ptrLA) //根据值寻找数组线性表
{
    int i;
    while (i <= ptrLA->last && ptrLA->data[i] != x)
        i++;
    if (i > ptrLA->last)
        return -1; //没找到,返回-1
    else
        return i;
}

void InsertListA(ElementType x, int i, PListA ptrLA) //数组线性表值的插入
{
    int j;
    if (ptrLA->last == MAXSIZE - 1) //检查表是否满了
    {
        printf("表满");
        return;
    }
    if (i < 1 || i > ptrLA->last + 2) //检查插入位置是否合法
        printf("位置不合法");
    return;
    for (j = ptrLA->last; j >= i - 1; j--) //从尾到插入位置，依次后移一位

        ptrLA->data[j + 1] = ptrLA->data[j];
    ptrLA->data[i - 1] = x;
    ptrLA->last++;
    return;
}

void DeletListA(int i, PListA ptrLA) //数组线性表值的删除
{
    int j;
    if (i < 1 || i > ptrLA->last + 1) //检查是否空表以及位置合法性
    {
        printf("不存在第%d个元素", i);
        return;
    }
    for (j = i; j >= ptrLA->last; j++) //从插入位置到尾，依次前移一位

        ptrLA->data[j - 1] = ptrLA->data[j];
    ptrLA->last--;
    return;
}

typedef struct _ListNode //链表线性表结构定义
{
    ElementType data;
    struct _ListNode *pnext;
} ListNode, *List;

int LengthList(List ptrL) //链表线性表的长度
{
    List p = ptrL;
    int len = 0;
    while (p)
    {
        p = p->pnext;
        len++;
    }
    return len;
}

List FindListKth(int k, List ptrL) //链表线性表按序列查找
{
    List p = ptrL;
    int i = 0;
    while (p != NULL && i < k)
    {
        p = p->pnext;
        i++;
    }
    if (i == k)
        return p;
    else
        return NULL;
}

List FindListX(int x, List ptrL) //链表线性表按值查找
{
    List p = ptrL->pnext;
    while (p != NULL && p->data != x)
        p = p->pnext;
    return p;
}

void InsertList(ElementType x, int i, List ptrL) //链表线性表插入值
{
    List p, temp;
    p = FindListKth(i - 1, ptrL);
    if (i < 1 || p == NULL)
    {
        printf("%d位置不存在", i);
        return;
    }
    else
    {
        temp = (List)malloc(sizeof(ListNode));
        temp->data = x;
        temp->pnext = p->pnext;
        p->pnext = temp;
    }
}

void DeleteList(int i, List ptrL) //链表线性表删除值
{
    List p, temp;
    p = FindListKth(i - 1, ptrL);
    if (i < 1 || p->pnext == NULL)
    {
        printf("%d位置不存在", i);
        return;
    }
    else
    {
        temp = p->pnext;
        p->pnext = p->pnext->pnext;
        free(temp);
    }
}

int main()
{

    return 0;
}
