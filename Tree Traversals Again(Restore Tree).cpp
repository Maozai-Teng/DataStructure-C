#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ElementTypeI int
#define ElementTypeBT Tree
#define MaxS 5

typedef struct _TreeNode *Tree;
typedef struct _TreeNode
{
    ElementTypeI data;
    struct _TreeNode *pleft;
    struct _TreeNode *pright;
} TreeNode;

typedef struct _StackNode *Stack;
typedef struct _StackNode
{
    ElementTypeBT data;
    struct _StackNode *pnext;
} StackNode;

Tree TreeNodeCreat()
{
    Tree tree = (Tree)malloc(sizeof(TreeNode));
    tree->pleft = NULL;
    tree->pright = NULL;
    return tree;
}

Stack StackCreat() //创造链表堆栈
{
    Stack stack = (Stack)malloc(sizeof(StackNode));
    stack->pnext = NULL;
    return stack;
}

int StackIsEmpty(Stack stack) //判断链表堆栈是否为空
{
    return (stack->pnext == NULL);
}

void StackPush(Stack stack, ElementTypeBT x)
{
    Stack s = (Stack)malloc(sizeof(StackNode));
    s->data = x;
    s->pnext = stack->pnext;
    stack->pnext = s;
}

ElementTypeBT StackPop(Stack stack)
{
    if (StackIsEmpty(stack))
        return NULL;
    else
    {
        Stack s;
        ElementTypeBT data;
        s = stack->pnext;
        stack->pnext = s->pnext;
        data = s->data;
        free(s);
        return data;
    }
}

Tree TreeCreat()
{
    int n, num;
    scanf("%d", &n);
    char string[MaxS];
    char push[MaxS] = "Push";

    Tree tree = TreeNodeCreat();
    scanf("%s %d", string, &num);
    tree->data = num;
    Tree ptree = tree;

    Stack s = StackCreat();
    StackPush(s, tree);

    for (int i = 1; i < 2 * n; i++)
    {
        scanf("%s", string);
        if (!strcmp(string, push))
        {
            scanf("%d", &num);
            Tree temp = TreeNodeCreat();
            temp->data = num;
            if (!(ptree->pleft))
            {
                ptree->pleft = temp;
                ptree = temp;
            }
            else
            {
                ptree->pright = temp;
                ptree = temp;
            }
            StackPush(s, temp);
        }
        else
            ptree = StackPop(s);
    }
    return tree;
}

void PostPaint(Tree tree, int *pflag)
{
    if (tree)
    {
        PostPaint(tree->pleft, pflag);
        PostPaint(tree->pright, pflag);
        if (*pflag)
            *pflag = 0;
        else
            printf(" ");
        printf("%d", tree->data);
    }
}

int main()
{
    int flag = 1;
    Tree tree = TreeCreat();
    PostPaint(tree, &flag);

    return 0;
}
