#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node *Stack;
typedef struct _Node
{
    int data;
    struct _Node *pnext;
} Node;

void Push(Stack stack, int x)
{
    Stack s;
    s = (Stack)malloc(sizeof(Node));
    s->data = x;
    s->pnext = stack->pnext;
    stack->pnext = s;
}

int Pop(Stack stack)
{
    if (!(stack->pnext))
        return NULL;
    Stack s;
    s = stack->pnext;
    stack->pnext = s->pnext;

    int pop = s->data;
    free(s);
    return pop;
}

int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    while (K--)
    {
        int a[N] = {0};
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        Stack stack;
        stack = (Stack)malloc(sizeof(Node));
        stack->pnext = NULL;
        int cnt = 0, mark = 0;
        for (int i = 0, j = 1; i < N;)
        {
            if (!(stack->pnext) || a[i] > stack->pnext->data)
            {
                Push(stack, j++);
                cnt++;
                if (cnt > M)
                {
                    mark = 1;
                    break;
                }
            }
            else if (a[i] == stack->pnext->data)
            {
                Pop(stack);
                cnt--;
                i++;
            }
            else //此时a[i]数值＜堆栈的顶部，说明出错
            {
                mark = 1;
                break;
            }
        }
        if (mark)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
