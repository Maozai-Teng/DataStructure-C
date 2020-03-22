#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElementType Tree
#define ElementTypei int
#define MaxS 5
#define MaxT (30 + 1)

typedef struct _TreeNode *Tree;
typedef struct _TreeNode
{
    ElementTypei data;
    struct _TreeNode *left;
    struct _TreeNode *right;
} TreeNode;

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

Tree CreateTree()
{
    Tree tree;
    tree = (Tree)malloc(sizeof(TreeNode));
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

Tree Restore(Tree tree)
{
    int n, num;
    StackL stack = CreatStackL();
    Tree ptree = tree;
    scanf("%d", &n);
    char string[MaxS];
    char Push[MaxS] = "Push";
    scanf("%s", &string);
    scanf("%d", &num);
    ptree->data = num;
    PushStackL(ptree, stack);
    for (int i = 1; i < 2 * n; i++)
    {
        scanf("%s", &string);
        if (!strcmp(string, Push))
        {
            scanf("%d", &num);
            Tree temp = CreateTree();
            temp->data = num;
            if (!(ptree->left))
            {
                ptree->left = temp;
                ptree = temp;
            }
            else if (!(ptree->right))
            {
                ptree->right = temp;
                ptree = temp;
            }
            PushStackL(temp, stack);
        }
        else
        {
            ptree = PopStackL(stack);
        }
    }
    return tree;
}

void PostPaint(Tree tree, int *pflag)
{
    if (tree)
    {
        PostPaint(tree->left, pflag);
        PostPaint(tree->right, pflag);
        if (*pflag)
            *pflag = 0;
        else
            printf(" ");
        printf("%d", tree->data);
    }
}

int main()
{
    Tree tree;
    int flag = 1;

    tree = CreateTree();
    tree = Restore(tree);
    PostPaint(tree, &flag);

    return 0;
}