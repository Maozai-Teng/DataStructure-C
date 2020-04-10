#include <stdio.h>
#include <stdlib.h>
#define ElementType BinTree
#define ElementTypeInt int

typedef struct _AVLTreeNode *AVLTree; //AVL树的结构
typedef struct _AVLTreeNode
{
    ElementTypeInt data;
    struct _AVLTreeNode *pleft;
    struct _AVLTreeNode *pright;
    int height;
} AVLTreeNode;

int GetHeight(AVLTree tree)
{
    return tree == NULL ? -1 : tree->height;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

AVLTree LLRotation(AVLTree tree) //LL旋转
{
    AVLTree treeleft = tree->pleft;
    tree->pleft = treeleft->pright;
    treeleft->pright = tree;
    tree->height = Max(GetHeight(tree->pleft), GetHeight(tree->pright)) + 1;
    treeleft->height = Max(GetHeight(treeleft->pleft), tree->height) + 1;
    return treeleft;
}

AVLTree RRRotation(AVLTree tree) //RR旋转
{
    AVLTree treeright = tree->pright;
    tree->pright = treeright->pleft;
    treeright->pleft = tree;
    tree->height = Max(GetHeight(tree->pleft), GetHeight(tree->pright)) + 1;
    treeright->height = Max(GetHeight(treeright->pright), tree->height) + 1;
    return treeright;
}

AVLTree LRRotation(AVLTree tree)           /*LR旋转*/
{                                          /*     */
    tree->pleft = RRRotation(tree->pleft); /*左结点先RR旋转*/
    return LLRotation(tree);               /*本体LL旋转*/
}

AVLTree RLRotation(AVLTree tree)             /*RL旋转*/
{                                            /*     */
    tree->pright = LLRotation(tree->pright); /*右结点先LL旋转*/
    return RRRotation(tree);                 /*本体RR旋转*/
}

AVLTree AVLInsert(ElementTypeInt x, AVLTree tree)
{
    if (!tree)
    {
        tree = (AVLTree)malloc(sizeof(AVLTreeNode));
        tree->data = x;
        tree->height = 0;
        tree->pleft = tree->pright = NULL;
    }
    else if (x < tree->data)
    {
        tree->pleft = AVLInsert(x, tree->pleft);
        if (GetHeight(tree->pleft) - GetHeight(tree->pright) == 2) /*先确定是L?旋转*/
        {                                                          /*             */
            if (x < tree->pleft->data)                             /*   LL旋转    */
                tree = LLRotation(tree);                           /*             */
            else                                                   /*             */
                tree = LRRotation(tree);                           /*   LR旋转    */
        }
    }
    else if (x > tree->data)
    {
        tree->pright = AVLInsert(x, tree->pright);
        if (GetHeight(tree->pleft) - GetHeight(tree->pright) == -2) /*先确定是R?旋转*/
        {                                                           /*             */
            if (x > tree->pright->data)                             /*   RR旋转    */
                tree = RRRotation(tree);                            /*             */
            else                                                    /*             */
                tree = RLRotation(tree);                            /*   RL旋转    */
        }
    }
    tree->height = Max(GetHeight(tree->pleft), GetHeight(tree->pright)) + 1; /* 更新树高 */
    return tree;
}

int main()
{
    AVLTree tree = NULL;
    int N, data;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data);
        tree = AVLInsert(data, tree);
    }
    printf("%d", tree->data);

    return 0;
}
