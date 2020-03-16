#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack
{
    int data;
    struct _Stack *pnext;
} Stack, *PStack;

void Push(int i, PStack top)
{
    PStack p;
    p = (PStack)malloc(sizeof(Stack));
    p->data = i;
    p->pnext = top->pnext;
    top->pnext = p;
}

int Pop(PStack top)
{
    if (top->pnext == NULL)
        return NULL;
    PStack p;
    p = top->pnext;
    top->pnext = p->pnext;
    int pop = p->data;
    free(p);
    return pop;
}

int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);

    while (K--)
    {
        int i;
        int a[N] = {0};
        for (i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
        }

        PStack s;
        s = (PStack)malloc(sizeof(Stack));
        s->pnext = NULL;

        i = 0;
        int j = 1, mark = 1, cnt = 0;
        while (mark && i < N)
        {
            if (!(s->pnext) || a[i] > s->pnext->data)
            {
                Push(j++, s);
                cnt++;
                if (cnt > M)
                {
                    mark = 0;
                    break;
                }
            }
            else if (a[i] == s->pnext->data)
            {
                Pop(s);
                cnt--;
                i++;
            }
            else
            {
                mark = 0;
                break;
            }
        }

        if (mark)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
