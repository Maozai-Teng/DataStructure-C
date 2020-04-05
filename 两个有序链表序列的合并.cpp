#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List L, rear, p1, p2;
    L = (List)malloc(sizeof(struct Node));
    rear = L;
    rear->Next = NULL;
    p1 = L1->Next;
    p2 = L2->Next;
    while (p1 && p2)
    {
        if (p1->Data <= p2->Data)
        {
            rear->Next = p1;
            p1 = p1->Next;
        }
        else
        {
            rear->Next = p2;
            p2 = p2->Next;
        }
        rear = rear->Next;
    }
    while (p1)
    {
        rear->Next = p1;
        p1 = p1->Next;
        rear = rear->Next;
    }
    while (p2)
    {
        rear->Next = p2;
        p2 = p2->Next;
        rear = rear->Next;
    }
    rear->Next = NULL;
    L1->Next = p1;
    L2->Next = p2;
    return L;
}