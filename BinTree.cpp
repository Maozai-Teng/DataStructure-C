#include <stdio.h>
#include <stdlib.h>
#define ElementType BinTree
#define ElementTypeInt int
#define MAXSIZE 100
#define ERROR -1

typedef struct _TreeNode *BinTree; //二叉树的结构
typedef struct _TreeNode
{
    ElementTypeInt data;
    struct _TreeNode *left;
    struct _TreeNode *right;
} TreeNode;

typedef struct _StackLNode //链表堆栈结构定义
{
    ElementType data;
    struct _StackLNode *pnext;
} StackLNode, *StackL;

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
    if (queueL->front->pnext == NULL)
        return NULL;
    PQLNode tempQLNode;
    ElementType item;

    tempQLNode = queueL->front->pnext;
    if (queueL->front->pnext == queueL->rear)
        queueL->rear = queueL->front;
    queueL->front->pnext = queueL->front->pnext->pnext;

    item = tempQLNode->data;
    free(tempQLNode);
    return item;
}

void PreOrderTraversal(BinTree bt) //先序遍历
{
    if (bt)
    {
        printf("%d", bt->data);
        PreOrderTraversal(bt->left);
        PreOrderTraversal(bt->right);
    }
}

void InOrderTraversal(BinTree bt) //中序遍历
{
    if (bt)
    {
        InOrderTraversal(bt->left);
        printf("%d", bt->data);
        InOrderTraversal(bt->right);
    }
}

void InOrderTraversalStack(BinTree bt) //中序遍历（非递归，堆栈法）（先序改位置就行）
{
    BinTree t;
    t = bt;
    StackL s = CreatStackL();
    while (t || !(IsEmptyStackL(s)))
    {
        while (t)
        {
            PushStackL(t, s);
            t = t->left;
        }
        if (!(IsEmptyStackL(s)))
        {
            t = PopStackL(s);
            printf("%5d", t->data);
            t = t->right;
        }
    }
}

void PostOrderTraversal(BinTree bt) //后序遍历
{
    if (bt)
    {
        PostOrderTraversal(bt->left);
        PostOrderTraversal(bt->right);
        printf("%d", bt->data);
    }
}

void LevelOrderTraversal(BinTree bt) // 层序遍历
{
    QueueL q;
    BinTree t = bt;
    if (!t)
        return;
    q = CreatQueueL();
    AddQL(t, q);
    while (IsEmptyQueueL(q))
    {
        t = DeleteQL(q);
        printf("%d\n", t->data);
        if (t->left)
            AddQL(t->left, q);
        if (t->right)
            AddQL(t->right, q);
    }
}

void PreOrderPrintLeaves(BinTree bt) //输出全部叶子
{
    if (bt)
    {
        if (!(bt->left) && !(bt->right))
            printf("%d", bt->data);
        PreOrderPrintLeaves(bt->left);
        PreOrderPrintLeaves(bt->right);
    }
}

int PostOrderTreeHeight(BinTree bt) //后序遍历算树高
{
    int maxH, leftH, rightH;
    if (bt)
    {
        leftH = PostOrderTreeHeight(bt->left);
        rightH = PostOrderTreeHeight(bt->right);
        maxH = (leftH > rightH) ? leftH : rightH;
        return (maxH + 1);
    }
    return 0;
}

void PostorderTraversalStack(BinTree bt) //后序遍历（非递归，堆栈法）
{
    BinTree t = bt, p = NULL;
    StackL s = CreatStackL();

    while (t || !(IsEmptyStackL(s)))
    {
        while (t)
        {
            PushStackL(t, s);
            t = t->left;
        }
        if (!(IsEmptyStackL(s)))
        {
            t = PopStackL(s);
            if (t->right == p || t->right == NULL)
            {                           /* 右孩子已访问或右孩子不存在, 弹出结点 */
                printf("%5d", t->data); /* 访问结点 */
                p = t;                  /* P指向被访问结点 */
                t = NULL;               /* 树置空(该树的左\右\根结点已经访问) */
            }
            else
            {
                PushStackL(t, s); /* 否则,不应该弹出结点, 结点再次入栈 */
                t = t->right;     /* 继续遍历右子树 */
            }
        }
    }
}

void PostorderTraversalStack(BinTree bt) /*后序遍历（非递归，双堆栈法）*/
{                                        /*先序是【中左右】，改成【中右左】*/
    BinTree t;                           /*然后堆栈倒叙变成【左右中】，就是后序*/
    t = bt;
    StackL s = CreatStackL();
    StackL s2 = CreatStackL();

    while (t || !(IsEmptyStackL(s)))
    {
        while (t)
        {
            PushStackL(t, s);
            PushStackL(t, s2);
            t = t->right;
        }
        if (!(IsEmptyStackL(s)))
        {
            t = PopStackL(s);
            t = t->left;
        }
    }
    while (!(IsEmptyStackL(s2)))
    {
        t = PopStackL(s2);
        printf("%5d", t->data);
    }
}

int main()
{
    printf("Maozai\n");

    return 0;
}
