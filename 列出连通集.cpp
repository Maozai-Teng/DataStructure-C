#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxN 11

typedef int Vertex;
typedef Vertex ElementType;

int N, E;
int Gragh[MaxN][MaxN] = {0};
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
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &v1, &v2);
        Gragh[v1][v2] = 1;
        Gragh[v2][v1] = 1;
    }
}

void DFS(Vertex v)
{
    Visit[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < N; i++)
    {
        if (!Visit[i] && Gragh[i][v])
            DFS(i);
    }
}

void BFS(Vertex v)
{
    QueueA queue;
    queue.front = queue.rear = 0;
    Vertex temp;
    QAAdd(&queue, v);
    Visit[v] = 1;
    while (queue.front != queue.rear)
    {
        temp = QADelete(&queue);
        printf("%d ", temp);
        for (int i = 0; i < N; i++)
        {
            if (!Visit[i] && Gragh[i][temp])
            {
                QAAdd(&queue, i);
                Visit[i] = 1;
            }
        }
    }
}

void ListComponent()
{
    for (int i = 0; i < N; i++)
    {
        if (!Visit[i])
        {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }
    }

    for (int i = 0; i < N; i++)
        Visit[i] = 0;

    for (int i = 0; i < N; i++)
    {
        if (!Visit[i])
        {
            printf("{ ");
            BFS(i);
            printf("}\n");
        }
    }
}

int main()
{
    scanf("%d %d", &N, &E);
    GraghBuild();
    ListComponent();

    return 0;
}
