PAddress reverse_good(PAddress P, PAddress last, int K, int N) //这个是对的 
{
    if (P == NULL || P->pnext == NULL)
        return P;
    PAddress head, rear, temp;
    int cnt = 1;
    head = P;
    rear = head->pnext;
    while (cnt < K)
    {
        temp = rear->pnext;
        rear->pnext = head;
        rear->next = head->pre;
        head = rear;
        rear = temp;
        cnt++;
    }
    P->pnext = rear;
    if (rear)
        P->next = rear->pre;
    else
        P->next = -1;
    temp = P;
    P = head;
    if (last)
    {
        last->next = head->pre;
        last->pnext = head;
    }
    N = N - K;
    if (N < K)
    {
        return P;
    }
    reverse_good(rear, temp, K, N);
    return P;
}

void reverse_good(PAddress P, PAddress last, int K, int N) //我现在改的 
{
    PAddress head, rear, temp;
    int cnt = 1;
    head = P;
    rear = head->pnext;
    while (cnt < K)
    {
        temp = rear->pnext;
        rear->pnext = head;
        rear->next = head->pre;
        head = rear;
        rear = temp;
        cnt++;
    }
    P->pnext = rear;
    if (rear)
        P->next = rear->pre;
    else
        P->next = -1;
    temp = P;
    P = head;
    if (last)
    {
        last->next = head->pre;
        last->pnext = head;
    }
    N = N - K;
    if (N >= K)
    {
        reverse_good(rear, temp, K, N);
    }
}
