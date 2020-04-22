#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxVertexNum 100
#define WeightType int
#define DataType int

typedef int Vertex;
typedef struct _GNode *PtrToGNode;
typedef struct _GNode
{
    int NV; //vertex number
    int NE; //edge number
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];

} GNode;
typedef PtrToGNode MGragph;

typedef struct _ENode *PtrToENode;
typedef struct _ENode
{
    Vertex V1, V2;
    WeightType Weight;
} ENode;
typedef PtrToENode Edge;

MGragph MGragphCreat(int VertexNum)
{
    Vertex v, w;
    MGragph mGraph = (MGragph)malloc(sizeof(GNode));
    mGraph->NV = VertexNum;
    mGraph->NE = 0;

    for (v = 0; v < mGraph->NV; v++)
    {
        for (w = 0; w < mGraph->NV; w++)
        {
            mGraph->G[v][w] = 0;
        }
    }
    return mGraph;
}

void MEdgeInsert(MGragph MG, Edge E)
{
    MG->G[E->V1][E->V2] = E->Weight;
    MG->G[E->V2][E->V1] = E->Weight; //无向图的操作，来回各一次
}

MGragph MGragphBuild()
{
    int nv;
    Vertex v;
    Edge edge;
    MGragph mGraph;
    scanf("%d", &nv);
    mGraph = MGragphCreat(nv);
    scanf("%d", mGraph->NE);
    if (mGraph->NE != 0)
    {
        edge = (Edge)malloc(sizeof(ENode));
        for (int i = 0; i < mGraph->NE; i++)
        {
            scanf("%d %d %d", &edge->V1, &edge->V2, &edge->Weight);
            MEdgeInsert(mGraph, edge);
        }
    }

    /*如果顶点有数据的话，读入*/
    for (v = 0; v < mGraph->NV; v++)
    {
        scanf(" %c", &(mGraph->Data[v]));
    }

    return mGraph;
}

typedef struct _AdjVNode *PtrToAdjNode;
typedef struct _AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjNode Next;
} AdjVNode;

typedef struct _VNode
{
    PtrToAdjNode FirstEdge;
    DataType Data;
} AdjList[MaxVertexNum];

typedef struct _LGNode *PtrToGNode;
typedef struct _LGNode
{
    int NV;
    int NE;
    AdjList G;
} LGNode;
typedef PtrToGNode LGragh;

LGragh LGraghCreat(int VertexNum)
{
    Vertex v, w;
    LGragh lGragh;
    lGragh = (LGragh)malloc(sizeof(LGNode));
    lGragh->NV = VertexNum;
    lGragh->NE = 0;
    for (v = 0; v < lGragh->NV; v++)
        lGragh->G[v].FirstEdge = NULL;

    return lGragh;
}

void LEdgeInsert(LGragh LG, Edge E)
{
    PtrToAdjNode newLNode;
    newLNode = (PtrToAdjNode)malloc(sizeof(AdjVNode));
    newLNode->AdjV = E->V2;
    newLNode->Weight = E->Weight;
    newLNode->Next = LG->G[E->V1].FirstEdge;
    LG->G[E->V1].FirstEdge = newLNode;

    PtrToAdjNode newLNode;
    newLNode = (PtrToAdjNode)malloc(sizeof(AdjVNode));
    newLNode->AdjV = E->V1;
    newLNode->Weight = E->Weight;
    newLNode->Next = LG->G[E->V2].FirstEdge;
    LG->G[E->V2].FirstEdge = newLNode;
}

LGragh LGragphBuild()
{
}

int main()
{
    return 0;
}
