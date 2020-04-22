#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxN 101
#define ElementType Node

typedef struct _Node
{
    int hor;
    int ver;
    int visit;
    int safe;
    int jump;
} Node;

typedef struct //数组队列结构定义
{
    ElementType data[MaxN];
    int front;
    int rear;
} QueueA, *PQueueA;

void AddQA(PQueueA ptrQA, ElementType x) //数组队列插入
{
    ptrQA->rear = (ptrQA->rear + 1) % MaxN;
    ptrQA->data[ptrQA->rear] = x;
}

ElementType DeleteQA(PQueueA ptrQA) //数组队列删除
{
    ptrQA->front = (ptrQA->front + 1) % MaxN;
    return (ptrQA->data[ptrQA->front]);
}

int N, D, IsSafe = 0;
Node Graph[MaxN];
const double diameter = 15.0;

double LenGet(int x1, int y1, int x2, int y2)
{
    return (sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)));
}

int NodeToShoreSafe(int x, int y)
{
    if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y - 50) <= D || abs(y + 50) <= D)
        return 1;
    else
        return 0;
}

void NodeSafe()
{
    for (int i = 0; i < N; i++)
    {
        if (NodeToShoreSafe(Graph[i].hor, Graph[i].ver))
            Graph[i].safe = 1;
        else
            Graph[i].safe = 0;
    }
}

void NodeJump()
{
    for (int i = 0; i < N; i++)
    {
        if (LenGet(Graph[i].hor, Graph[i].ver, 0, 0) <= D + diameter / 2)
            Graph[i].jump = 1;
        else
            Graph[i].jump = 0;
    }
}

void BFS(int v)
{
    Graph[v].visit = 1;
    Node temp;
    QueueA queue;
    queue.front = queue.rear = 0;
    AddQA(&queue, Graph[v]);
    while (queue.front != queue.rear)
    {
        temp = DeleteQA(&queue);
        if (temp.safe)
        {
            IsSafe = 1;
            return;
        }

        for (int i = 0; i < N; i++)
        {
            if (!Graph[i].visit && (LenGet(temp.hor, temp.ver, Graph[i].hor, Graph[i].ver) <= D))
            {
                Graph[i].visit = 1;
                AddQA(&queue, Graph[i]);
            }
        }
    }
}

void ListComponent()
{
    for (int i = 0; i < N; i++)
    {
        if (!Graph[i].visit && Graph[i].jump)
        {
            BFS(i);
            if (IsSafe)
                break;
        }
    }
    if (IsSafe)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &Graph[i].hor, &Graph[i].ver);
        Graph[i].visit = 0;
    }
    NodeSafe();
    NodeJump();

    ListComponent();

    return 0;
}
