#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxN 1001

typedef int Vertex;
typedef Vertex ElementType;

typedef struct _VNode *AdjList;
typedef struct _VNode
{
    Vertex adjV;
    AdjList next;
} VNode;

int N, M;
AdjList Gragh[MaxN];
int Visit[MaxN] = {0};

typedef struct //数组队列结构定义
{
    ElementType data[MaxN];
    int front;
    int rear;
} QueueA, *PQueueA;

void QAAdd(PQueueA PtrQA, ElementType X) //数组队列插入
{
    PtrQA->rear = (PtrQA->rear + 1) % MaxN;
    PtrQA->data[PtrQA->rear] = X;
}

ElementType QADelete(PQueueA PtrQA) //数组队列删除
{
    PtrQA->front = (PtrQA->front + 1) % MaxN;
    return (PtrQA->data[PtrQA->front]);
}

void GraghBuild()
{
    Vertex v1, v2;
    AdjList newNode;
    for (int i = 1; i <= N; i++)
    {
        Gragh[i] = (AdjList)malloc(sizeof(VNode));
        Gragh[i]->adjV = i;
        Gragh[i]->next = NULL;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &v1, &v2);

        newNode = (AdjList)malloc(sizeof(VNode));
        newNode->adjV = v2;
        newNode->next = Gragh[v1]->next;
        Gragh[v1]->next = newNode;

        newNode = (AdjList)malloc(sizeof(VNode));
        newNode->adjV = v1;
        newNode->next = Gragh[v2]->next;
        Gragh[v2]->next = newNode;
    }
}

int BFS(Vertex v)
{
    QueueA queue;
    queue.front = queue.rear = 0;
    Vertex tempV;
    AdjList tempAdj;
    int count = 1, tail, last = v, level = 0;

    QAAdd(&queue, v);
    Visit[v] = 1;
    while (queue.front != queue.rear)
    {
        tempV = QADelete(&queue);
        tempAdj = Gragh[tempV]->next;
        while (tempAdj)
        {
            if (!Visit[tempAdj->adjV])
            {
                QAAdd(&queue, tempAdj->adjV);
                Visit[tempAdj->adjV] = 1;
                count++;
                tail = tempAdj->adjV;
            }
            tempAdj = tempAdj->next;
        }
        if (tempV == last)
        {
            level++;
            last = tail;
        }
        if (level == 6)
            break;
    }
    return count;
}

void SDS()
{
    int count = 0;
    double result = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            Visit[j] = 0;
        count = BFS(i);
        result = 100.0 * count / N;
        printf("%d: %.2f%%\n", i, result);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    GraghBuild();
    SDS();

    return 0;
}
