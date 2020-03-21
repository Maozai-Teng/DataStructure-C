#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElementType int
#define MaxS 5
#define MaxT (30 + 1)

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

void PushStackL(ElementType x, StackL stackL) //链表堆栈入栈
{
    StackL tempStack;
    tempStack = (StackL)malloc(sizeof(StackLNode));
    tempStack->data = x;
    tempStack->pnext = stackL->pnext;
    stackL->pnext = tempStack;
}

ElementType PopStackL(StackL stackL) //链表堆栈出栈
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

void Paintout(StackL stackOut) //递归按格式输出
{
    StackL p;
    p = stackOut;
    if (p->pnext->pnext)
    {
        Paintout(p->pnext);
    }
    if (p->pnext->pnext)
        printf(" ");
    printf("%d", p->pnext->data);
}

int main()
{
    StackL stackIn, stackOut;
    stackIn = CreatStackL();
    stackOut = CreatStackL();
    int n, num, flag = 1, out = 0; //用flag判断上一步是Push还是Pop
    scanf("%d", &n);
    int *mark = (int *)calloc(n + 1, sizeof(int));
    // int mark[MaxT] = {0};
    char string[MaxS];
    char Push[MaxS] = "Push";
    while (n)
    {

        scanf("%s", &string);
        if (!strcmp(string, Push)) //接收到Push的步骤
        {
            if (flag == 0)
                PushStackL(out, stackIn);
            scanf("%d", &num);
            PushStackL(num, stackIn);
            flag = 1;
        }
        else //接收到Pop的步骤
        {
            if (flag == 1)
                out = num;
            if (mark[out] == 0)
                out = PopStackL(stackIn);
            else
            {
                while (mark[out] == 1)
                {
                    PushStackL(out, stackOut);
                    out = PopStackL(stackIn);
                }
            }
            mark[out] = 1;
            n--;
            flag = 0;
            if (!n) //最后一步，把全部的东西都输出
            {
                PushStackL(out, stackOut);
                while (stackIn->pnext)
                {
                    out = PopStackL(stackIn);
                    PushStackL(out, stackOut);
                }
            }
        }
    }

    Paintout(stackOut); //递归按格式输出

    return 0;
}