#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ElementTypeI int

typedef struct _TreeNode *Tree;
typedef struct _TreeNode
{
    ElementTypeI data;
    struct _TreeNode *pleft;
    struct _TreeNode *pright;
    int flag;
} TreeNode;

Tree TreeNodeCreat(int data)
{
    Tree tree = (Tree)malloc(sizeof(TreeNode));
    tree->data = data;
    tree->pleft = tree->pright = NULL;
    tree->flag = 0;
    return tree;
}

Tree TreeInsert(Tree tree, int data)
{
    if (!tree)
        tree = TreeNodeCreat(data);
    else
    {
        if (data < tree->data)
            tree->pleft = TreeInsert(tree->pleft, data);
        else
            tree->pright = TreeInsert(tree->pright, data);
    }
    return tree;
}

Tree TreeCreat(int N)
{
    int data;
    scanf("%d", &data);
    Tree tree = TreeNodeCreat(data);
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &data);
        tree = TreeInsert(tree, data);
    }
    return tree;
}

int TreeCheck(Tree tree, int data)
{
    if (tree->flag)
    {
        if (data < tree->data)
            TreeCheck(tree->pleft, data);
        else if (data > tree->data)
            TreeCheck(tree->pright, data);
        else
            return 0;
    }
    else
    {
        if (data == tree->data)
        {
            tree->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int TreeJudge(Tree tree, int N)
{
    int data, mark = 0;
    scanf("%d", &data);
    if (data != tree->data)
        mark = 1;
    else
        tree->flag = 1;
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &data);
        if (!mark && !TreeCheck(tree, data))
            mark = 1;
    }
    return !(mark);
}

void TreeReset(Tree tree)
{
    tree->flag = 0;
    if (tree->pleft)
        TreeReset(tree->pleft);
    if (tree->pright)
        TreeReset(tree->pright);
}

void TreeFree(Tree tree)
{
    if (tree->pleft)
        TreeFree(tree->pleft);
    if (tree->pright)
        TreeFree(tree->pright);
    free(tree);
}

int main()
{
    int N, L;
    Tree tree;
    scanf("%d", &N);
    while (N)
    {
        scanf("%d", &L);
        tree = TreeCreat(N);
        for (int i = 0; i < L; i++)
        {
            if (TreeJudge(tree, N))
                printf("Yes\n");
            else
                printf("No\n");
            TreeReset(tree);
        }
        TreeFree(tree);
        scanf("%d", &N);
    }

    return 0;
}
