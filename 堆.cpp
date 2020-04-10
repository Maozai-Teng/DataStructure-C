#include <stdio.h>
#include <stdlib.h>

#define ElementeTypeInt int
#define ElementeType HuffmanTree
#define MaxData 100000

typedef struct _HeapStruct *MaxHeap;
typedef struct _HeapStruct
{
    ElementeTypeInt *array;
    int size;
    int capacity;
} HeapStruct;

int MaxHeapIsFull(MaxHeap maxHeap)
{
    return (maxHeap->size == maxHeap->capacity);
}

int MaxHeapIsEmpty(MaxHeap maxHeap)
{
    return (maxHeap->size == 0);
}

MaxHeap MaxHeapCreate(int maxSize)
{
    MaxHeap maxHeap = (MaxHeap)malloc(sizeof(HeapStruct));
    maxHeap->array = (ElementeTypeInt *)malloc((maxSize + 1) * sizeof(ElementeTypeInt));
    maxHeap->size = 0;
    maxHeap->capacity = maxSize;
    maxHeap->array[0] = MaxData;
    return maxHeap;
}

void MaxHeapInsert(MaxHeap maxHeap,ElementeTypeInt x)
{
    if (MaxHeapIsFull(maxHeap))
    {
        printf("最大堆已满");
        return;
    }
    int i;
    i = ++maxHeap->size;
    for (; x > maxHeap->array[i / 2]; i /= 2)
        maxHeap->array[i] = maxHeap->array[i / 2];
    maxHeap->array[i] = x;
}

int MaxHeapDelete(MaxHeap maxHeap)
{
    if (MaxHeapIsEmpty(maxHeap))
    {
        printf("最大堆已空");
        return;
    }
    ElementeTypeInt max, temp;
    int parent, child;
    max = maxHeap->array[1];
    temp = maxHeap->array[maxHeap->size--];
    for (parent = 1; parent * 2 <= maxHeap->size; parent = child)
    {
        child = parent * 2;
        if ((child != maxHeap->size) && (maxHeap->array[child] < maxHeap->array[child + 1]))
            child++;
        if (maxHeap->array[child] <= temp)
            break;
        else
            maxHeap->array[parent] = maxHeap->array[child];
    }
    maxHeap->array[parent] = temp;
    return max;
}

MaxHeap MaxHeapBuild(MaxHeap maxHeap)
{
    int i, parent, child;
    ElementeTypeInt temp;
    for (i = maxHeap->size / 2; i > 0; i--) //从最后一个父结点开始
    {
        temp = maxHeap->array[i];
        for (parent = i; parent * 2 <= maxHeap->size; parent = child)
        {
            child = parent * 2;
            if ((child != maxHeap->size) && (maxHeap->array[child] < maxHeap->array[child + 1]))
                child++;
            if (maxHeap->array[child] <= temp)
                break;
            else
                maxHeap->array[parent] = maxHeap->array[child];
        }
        maxHeap->array[parent] = temp;
    }
    return maxHeap;
}

int main()
{
    printf("Maozai\n");

    return 0;
}
