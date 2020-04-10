#include <stdio.h>
#include <stdlib.h>
#define ElementType BinTree
#define ElementTypeInt int

typedef struct _TreeNode *BinTree; //二叉树的结构
typedef struct _TreeNode
{
    ElementTypeInt data;
    struct _TreeNode *pleft;
    struct _TreeNode *pright;
} TreeNode;

BinTree BSTFind(BinTree BST, ElementTypeInt x) //递归方法
{
    if (!BST)
        return NULL;
    if (x > BST->data)
        return BSTFind(BST->pright, x);
    else if (x < BST->data)
        return BSTFind(BST->pleft, x);
    else
        return BST;
}

BinTree BSTFind(BinTree BST, ElementTypeInt x) //循环方法
{
    while (BST)
    {
        if (x > BST->data)
            BST = BST->pright;
        else if (x < BST->data)
            BST = BST->pleft;
        else
            break;
    }
    return BST;
}

BinTree BSTFindMin(BinTree BST)
{
    if (!BST)
        return NULL;
    if (!BST->pleft)
        return BST;
    else
        return BSTFindMin(BST->pleft);
}

BinTree BSTFindMax(BinTree BST)
{
    if (!BST)
    {
        while (BST->pright)
            BST = BST->pright;
    }
    return BST;
}

BinTree BSTInsert(BinTree BST, ElementTypeInt x)
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(TreeNode));
        BST->data = x;
        BST->pleft = BST->pright = NULL;
    }
    else if (x < BST->data)
        BST->pleft = BSTInsert(BST->pleft, x);
    else if (x > BST->data)
        BST->pright = BSTInsert(BST->pright, x);
    return BST;
}

BinTree BSTDelete(BinTree BST, ElementTypeInt x)
{
    BinTree temp;
    if (!BST)
        printf("NotFind");
    else if (x < BST->data)
        BST->pleft = BSTDelete(BST->pleft, x);
    else if (x > BST->data)
        BST->pright = BSTDelete(BST->pright, x);
    else
    {
        if (BST->pleft && BST->pright)
        {
            temp = BSTFindMin(BST->pright);
            BST->data = temp->data;
            BST->pright = BSTDelete(BST->pright, BST->data);
        }
        else
        {
            temp = BST;
            if (!BST->pleft)
                BST = BST->pright;
            else if (!BST->pright)
                BST = BST->pleft;
            free(temp);
        }
    }
    return BST;
}

int main()
{
    printf("Maozai\n");

    return 0;
}
