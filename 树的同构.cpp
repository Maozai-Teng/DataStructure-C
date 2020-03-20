#include <stdio.h>
#include <stdlib.h>
#define ElementType char
#define Tree int
#define MaxTree 10
#define Null -1

typedef struct _TreeNode *BinTree;
typedef struct _TreeNode
{
    ElementType data;
    Tree left;
    Tree right;
} TreeNode;

TreeNode T1[MaxTree], T2[MaxTree];

Tree BuildTree(TreeNode t[])
{
    Tree root = Null;
    int num;
    scanf("%d\n", &num);
    if (num)
    {
        int check[MaxTree] = {0};
        int i;
        char cl, cr;
        for (i = 0; i < num; i++)
        {
            if (i < num - 1)
                scanf("%c %c %c\n", &t[i].data, &cl, &cr);
            else
                scanf("%c %c %c", &t[i].data, &cl, &cr);
            if (cl != '-')
            {
                t[i].left = cl - '0';
                check[t[i].left] = 1;
            }
            else
                t[i].left = Null;
            if (cr != '-')
            {
                t[i].right = cr - '0';
                check[t[i].right] = 1;
            }
            else
                t[i].right = Null;
        }
        for (i = 0; i < num; i++)
        {
            if (!check[i])
                break;
        }
        root = i;
    }
    return root;
}

int TG(Tree tree1, Tree tree2) //查看是否同构TG
{
    //都空，同构
    if ((tree1 == Null) && (tree2 == Null))
        return 1;
    //只有一边空，不同构
    if (((tree1 == Null) && (tree2 != Null)) || (tree1 != Null) && (tree2 == Null))
        return 0;
    //两边值不一样，不同构
    if (T1[tree1].data != T2[tree2].data)
        return 0;
    //左边指向一样，查看左右是不是一样
    if (((T1[tree1].left != Null) && (T2[tree2].left != Null)) && ((T1[T1[tree1].left].data) == (T2[T2[tree2].left].data)))
        return (TG(T1[tree1].left, T2[tree2].left) && TG(T1[tree1].right, T2[tree2].right));
    //左边指向不一样，调转查看左右是不是一样
    else
        return (TG(T1[tree1].left, T2[tree2].right) && TG(T1[tree1].right, T2[tree2].left));
}

int main()
{
    //建立两个二叉树
    Tree tree1, tree2;
    tree1 = BuildTree(T1);
    tree2 = BuildTree(T2);

    //判别是否同构
    if (TG(tree1, tree2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}