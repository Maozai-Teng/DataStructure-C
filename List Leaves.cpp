#include <stdio.h>
#include <stdlib.h>
#define ElementType Tree
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

typedef struct _QueueLNode //链表队列结点结构定义
{
    ElementType data;
    struct _QueueLNode *pnext;
} QueueLNode, *PQLNode;

typedef struct _QueueL //链表队列结构定义
{
    PQLNode rear;
    PQLNode front;
} * QueueL;

QueueL CreatQueueL() //建立新的链表队列
{
    PQLNode tempQueue;
    tempQueue = (PQLNode)malloc(sizeof(QueueLNode));
    tempQueue->pnext = NULL;
    QueueL queuel;
    queuel = (QueueL)malloc(sizeof(struct _QueueL));
    queuel->front = tempQueue;
    queuel->rear = tempQueue;
    return queuel;
}

int IsEmptyQueueL(QueueL queueL) //判断队列是否为空
{
    return (queueL->front->pnext == NULL);
}

void AddQL(ElementType x, QueueL QueueL) //链表队列插入
{
    PQLNode tempQueue;
    tempQueue = (PQLNode)malloc(sizeof(QueueLNode));
    tempQueue->data = x;
    tempQueue->pnext = NULL;
    QueueL->rear->pnext = tempQueue;
    QueueL->rear = tempQueue;
}

ElementType DeleteQL(QueueL queueL) //链表队列删除
{
    PQLNode tempQLNode;
    ElementType item;
    if (queueL->front->pnext == NULL)
    {
        return NULL;
    }
    tempQLNode = queueL->front->pnext;
    if (queueL->front->pnext == queueL->rear)
    {
        queueL->rear = queueL->front;
        queueL->front->pnext = NULL;
    }
    else
        queueL->front->pnext = queueL->front->pnext->pnext;
    item = tempQLNode->data;
    free(tempQLNode);
    return item;
}

TreeNode T[MaxTree];

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
            T[i].data = i;
            if (i < num - 1)
                scanf("%c %c\n", &cl, &cr);
            else
                scanf("%c %c", &cl, &cr);
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

int Flag = 0;
void PaintLeaves(Tree tree) //按照自顶向下和从左到右的顺序输出叶子
{
    QueueL q;
    Tree t = tree;
    if (tree == Null)
        return;
    q = CreatQueueL();
    AddQL(t, q);
    while (!IsEmptyQueueL(q))
    {
        t = DeleteQL(q);
        if (T[t].left == Null && T[t].right == Null)
        {
            if (!Flag)
                Flag = 1;
            else
                printf(" ");
            printf("%d", t);
        }
        if (T[t].left != Null)
            AddQL(T[T[t].left].data, q);
        if (T[t].right != Null)
            AddQL(T[T[t].right].data, q);
    }
}

int main()
{
    //建立二叉树
    Tree tree;
    tree = BuildTree(T);

    //按照自顶向下和从左到右的顺序输出叶子
    PaintLeaves(tree);

    return 0;
}