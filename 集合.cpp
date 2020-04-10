#include <stdio.h>
#include <malloc.h>
#define ElementTypeInt int
#define MaxSize 1000

typedef struct _SetType
{
    ElementTypeInt data;
    int parent;
} SetType;

int SetTypeFind(SetType s[], ElementTypeInt x)
{
    int i;
    for (i = 0; i < MaxSize && s[i].data != x; i++)
        ;
    if (i >= MaxSize)
        return -1;
    for (; s[i].parent >= 0; i = s[i].parent)
        ;
    return i;
}

void SetTypeUnion(SetType s[], ElementTypeInt x1, ElementTypeInt x2)
{
    int root1, root2;
    root1 = SetTypeFind(s, x1);
    root2 = SetTypeFind(s, x2);
    if (root1 != root2)
        s[root2].parent = root1;
}

int main()
{
    return 0;
}
