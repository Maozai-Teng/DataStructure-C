#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _PolyNode *Polynomial;
typedef struct _PolyNode
{
    int coef;
    int exp;
    struct _PolyNode *next;
} PolyNode;

void PolyAttach(Polynomial *rear, int coef, int exp)
{
    Polynomial p;
    p = (Polynomial)malloc(sizeof(PolyNode));
    p->coef = coef;
    p->exp = exp;
    p->next = NULL;
    (*rear)->next = p;
    (*rear) = (*rear)->next;
}

Polynomial PolyRead()
{
    Polynomial p, rear;
    p = (Polynomial)malloc(sizeof(PolyNode));
    p->next = NULL;
    rear = p;
    int n, coef, exp;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &coef, &exp);
        PolyAttach(&rear, coef, exp);
    }
    return p;
}

Polynomial PolyAdd(Polynomial p1, Polynomial p2)
{
    Polynomial pA, rear, t1, t2;
    pA = (Polynomial)malloc(sizeof(PolyNode));
    pA->next = NULL;
    rear = pA;
    int sum = 0;
    t1 = p1->next;
    t2 = p2->next;
    while (t1 && t2)
    {
        if (t1->exp > t2->exp)
        {
            PolyAttach(&rear, t1->coef, t1->exp);
            t1 = t1->next;
        }
        else if (t1->exp < t2->exp)
        {
            PolyAttach(&rear, t2->coef, t2->exp);
            t2 = t2->next;
        }
        else
        {
            sum = t1->coef + t2->coef;
            if (sum)
                PolyAttach(&rear, sum, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    for (; t1; t1 = t1->next)
        PolyAttach(&rear, t1->coef, t1->exp);
    for (; t2; t2 = t2->next)
        PolyAttach(&rear, t2->coef, t2->exp);
    return pA;
}

Polynomial PolyMult(Polynomial p1, Polynomial p2)
{
    Polynomial pM, rear, t1, t2;
    pM = (Polynomial)malloc(sizeof(PolyNode));
    pM->next = NULL;
    rear = pM;

    Polynomial pT, temp;
    pT = (Polynomial)malloc(sizeof(PolyNode));
    temp = (Polynomial)malloc(sizeof(PolyNode));
    pT->next = temp;
    temp->next = NULL;

    for (t1 = p1->next; t1; t1 = t1->next)
    {
        for (t2 = p2->next; t2; t2 = t2->next)
        {
            temp->coef = t1->coef * t2->coef;
            temp->exp = t1->exp + t2->exp;
            pM = PolyAdd(pM, pT);
        }
    }
    free(temp);
    free(pT);
    return pM;
}

void PolyPrint(Polynomial p)
{
    int flag = 0;
    Polynomial t = p->next;
    if (!t)
    {
        printf("0 0\n");
        return;
    }
    while (t)
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");

        printf("%d %d", t->coef, t->exp);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    Polynomial p1, p2, pM, pA;
    //读入多项式
    p1 = PolyRead();
    p2 = PolyRead();

    //乘法并输出
    pM = PolyMult(p1, p2);
    PolyPrint(pM);

    //加法并输出
    pA = PolyAdd(p1, p2);
    PolyPrint(pA);
}
