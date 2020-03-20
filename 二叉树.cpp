#include <stdio.h>
#include <stdlib.h>
#define ElementType BinTree
// #define ElementType int
#define MAXSIZE 100
#define ERROR -1

typedef struct _TreeNode *BinTree;
typedef struct _TreeNode
{
    ElementType data;
    struct _TreeNode *left;
    struct _TreeNode *right;
} TreeNode;

typedef struct _StackLNode //�����ջ�ṹ����
{
    ElementType data;
    struct _StackLNode *pnext;
} StackLNode, *StackL;

StackL CreatStackL() //���������ջ
{
    StackL stackL;
    stackL = (StackL)malloc(sizeof(StackLNode));
    stackL->pnext = NULL;
    return stackL;
}

int IsEmptyStackL(StackL stackL) //�ж������ջ�Ƿ�Ϊ��
{
    return (stackL->pnext == NULL);
}

void PushStackL(ElementType x, StackL stackL) //�����ջ��ջ
{
    StackL tempStack;
    tempStack = (StackL)malloc(sizeof(StackLNode));
    tempStack->data = x;
    tempStack->pnext = stackL->pnext;
    stackL->pnext = tempStack;
}

ElementType PopStackL(StackL stackL) //�����ջ��ջ
{
    StackL tempStack;
    ElementType item;
    if (IsEmptyStackL(stackL))
    {
        printf("ջ����");
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

void PreOrderTraversal(BinTree bt)
{
    if (bt)
    {
        printf("%d", bt->data);
        PreOrderTraversal(bt->left);
        PreOrderTraversal(bt->right);
    }
}

void InOrderTraversal(BinTree bt)
{
    if (bt)
    {
        InOrderTraversal(bt->left);
        printf("%d", bt->data);
        InOrderTraversal(bt->right);
    }
}

void InOrderTraversalStack(BinTree bt)
{
    BinTree t;
    t = bt;
    StackL s = CreatStackL();
    while (t || !(IsEmptyStackL(s)))
    {
        while (t)
        {
            PushStackL(t, s);
        }
    }
}

void PostOrderTraversal(BinTree bt)
{
    if (bt)
    {
        PostOrderTraversal(bt->left);
        PostOrderTraversal(bt->right);
        printf("%d", bt->data);
    }
}

int main()
{
    printf("���п���\n");
    // printf("%d\n",sizeof(int));
    // printf("%d\n",sizeof(BinTree));
    return 0;
}
