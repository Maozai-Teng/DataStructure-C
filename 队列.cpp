#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define MAXSIZE 100
#define ERROR -1

typedef struct //数组队列结构定义
{
    ElementType data[MAXSIZE];
    int front;
    int rear;
} QueueA, *PQueueA;

void AddQA(PQueueA ptrQA, ElementType x) //数组队列插入
{
    if ((ptrQA->rear + 1) % MAXSIZE == ptrQA->front)
    {
        printf("队列满了");
        return;
    }
    else
    {
        ptrQA->rear = (ptrQA->rear + 1) % MAXSIZE;
        ptrQA->data[ptrQA->rear] = x;
    }
}

ElementType DeleteQA(PQueueA ptrQA) //数组队列删除
{
    if (ptrQA->rear == ptrQA->front)
    {
        printf("队列空了");
        return ERROR;
    }
    else
    {
        ptrQA->front = (ptrQA->front + 1) % MAXSIZE;
        return (ptrQA->data[ptrQA->front]);
    }
}

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

int main()
{
    printf("队列空了");
    return 0;
}
