#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxN 101

typedef struct _Node
{
    int hor;
    int ver;
    int visit;
    int safe;
    int jump;
} Node;

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

void DFS(int v)
{
    Graph[v].visit = 1;
    if (Graph[v].safe)
    {
        IsSafe = 1;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!Graph[i].visit && (LenGet(Graph[v].hor, Graph[v].ver, Graph[i].hor, Graph[i].ver) <= D))
        {
            DFS(i);
            if (IsSafe)
                return;
        }
    }
}

void ListComponent()
{
    for (int i = 0; i < N; i++)
    {
        if (!Graph[i].visit && Graph[i].jump)
        {
            DFS(i);
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
