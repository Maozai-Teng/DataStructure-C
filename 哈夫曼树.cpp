#include <stdio.h>
#include <stdlib.h>

#define ElementeTypeInt int
#define ElementeType HuffmanTree
#define MinData -100000

typedef struct _HeapStruct *MinHeap;
typedef struct _HeapStruct
{
    ElementeType *array;
    int size;
    int capacity;
} HeapStruct;

typedef struct _HuffTreeNode *HuffmanTree;
typedef struct _HuffTreeNode
{
    int weight;
    HuffmanTree pleft;
    HuffmanTree pright;
} HuffTreeNode;

int MinHeapIsFull(MinHeap minHeap)
{
    return (minHeap->size == minHeap->capacity);
}

int MinHeapIsEmpty(MinHeap minHeap)
{
    return (minHeap->size == 0);
}

MinHeap MinHeapCreate(int minSize)
{
    MinHeap minHeap = (MinHeap)malloc(sizeof(HeapStruct));
    minHeap->array = (ElementeType *)malloc((minSize + 1) * sizeof(ElementeType));
    minHeap->size = 0;
    minHeap->capacity = minSize;
    minHeap->array[0]->weight = MinData;
    return minHeap;
}

void MinHeapInsert(MinHeap minHeap, HuffmanTree huffTree)
{
    if (MinHeapIsFull(minHeap))
    {
        printf("最小堆已满");
        return;
    }
    int i;
    i = ++minHeap->size;
    for (; huffTree->weight < minHeap->array[i / 2]->weight; i /= 2)
        minHeap->array[i] = minHeap->array[i / 2];
    minHeap->array[i] = huffTree;
}

HuffmanTree MinHeapDelete(MinHeap minHeap)
{
    if (MinHeapIsEmpty(minHeap))
    {
        printf("最小堆已空");
        return;
    }
    ElementeType min, temp;
    int parent, child;
    min = minHeap->array[1];
    temp = minHeap->array[minHeap->size--];
    for (parent = 1; parent * 2 <= minHeap->size; parent = child)
    {
        child = parent * 2;
        if ((child != minHeap->size) && (minHeap->array[child]->weight > minHeap->array[child + 1]->weight))
            child++;
        if (minHeap->array[child]->weight >= temp->weight)
            break;
        else
            minHeap->array[parent] = minHeap->array[child];
    }
    minHeap->array[parent] = temp;
    return min;
}

MinHeap MinHeapBuild(MinHeap minHeap)
{
    int i, parent, child;
    ElementeType temp;
    for (i = minHeap->size / 2; i > 0; i--) //从最后一个父结点开始
    {
        temp = minHeap->array[i];
        for (parent = i; parent * 2 <= minHeap->size; parent = child)
        {
            child = parent * 2;
            if ((child != minHeap->size) && (minHeap->array[child]->weight > minHeap->array[child + 1]->weight))
                child++;
            if (minHeap->array[child]->weight >= temp->weight)
                break;
            else
                minHeap->array[parent] = minHeap->array[child];
        }
        minHeap->array[parent] = temp;
    }
    return minHeap;
}

HuffmanTree HuffTreeNodeCreat(int x)
{
    HuffmanTree huffTree = (HuffmanTree)malloc(sizeof(HuffTreeNode));
    huffTree->weight = x;
    huffTree->pleft = NULL;
    huffTree->pright = NULL;
    return huffTree;
}

HuffmanTree Huffman(MinHeap minHeap)
{
    int i;
    HuffmanTree huffTree;

    MinHeapBuild(minHeap);
    for (i = 1; i < minHeap->size; i++) //做size-1次合并
    {
        huffTree = (HuffmanTree)malloc(sizeof(HuffTreeNode));
        huffTree->pleft = MinHeapDelete(minHeap);
        huffTree->pright = MinHeapDelete(minHeap);
        huffTree->weight = huffTree->pleft->weight + huffTree->pright->weight;
        MinHeapInsert(minHeap, huffTree);
    }
    huffTree = MinHeapDelete(minHeap);
    return huffTree;
}

int main()
{
    printf("Maozai\n");

    return 0;
}
