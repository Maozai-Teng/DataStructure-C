#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAXSIZE 100
#define ERROR -1

typedef struct //数组堆栈结构定义
{
    ElementType data[MAXSIZE];
    int top;
} StackA, *PStackA;

void PushSA(PStackA ptrSA, ElementType x) //数组堆栈入栈
{
    if (ptrSA->top == MAXSIZE - 1)
    {
        printf("栈满了");
        return;
    }
    else
    {
        ptrSA->data[++(ptrSA->top)] = x;
        return;
    }
}

ElementType PopSA(PStackA ptrSA) //数组堆栈出栈
{
    if (ptrSA->top == -1)
    {
        printf("栈空了");
        return ERROR;
    }
    else

        return (ptrSA->data[(ptrSA->top)--]);
}

typedef struct _StackLNode //链表堆栈结构定义
{
    ElementType data;
    struct _StackLNode *pnext;
} StackLNode, *StackL;

StackL CreatStackL() //创造链表堆栈
{
    StackL stackL;
    stackL = (StackL)malloc(sizeof(StackLNode));
    stackL->pnext = NULL;
    return stackL;
}

int IsEmptyStackL(StackL stackL) //判断链表堆栈是否为空
{
    return (stackL->pnext == NULL);
}

void PushStackL(ElementType x, StackL stackL)//链表堆栈入栈
{
    StackL tempStack;
    tempStack = (StackL)malloc(sizeof(StackLNode));
    tempStack->data = x;
    tempStack->pnext = stackL->pnext;
    stackL->pnext = tempStack;
}

ElementType PopStackL(StackL stackL)//链表堆栈出栈
{
    StackL tempStack;
    ElementType item;
    if (IsEmptyStackL(stackL))
    {
        printf("栈空了");
        return NULL;
    }
    else
    {
        tempStack = stackL->pnext;
        item = tempStack->data;
        stackL->pnext = tempStack->pnext;
        free(tempStack);
        return item;
    }
}

int main()
{

    return 0;
}
