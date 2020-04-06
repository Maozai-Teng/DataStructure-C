#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node *List;
typedef struct _Node
{
    int pre;
    int data;
    int next;
    struct _Node *pnext;
} Node;

void ListAttach(List *prear, int pre, int data, int next)
{
    List list = (List)malloc(sizeof(Node));
    list->pre = pre;
    list->data = data;
    list->next = next;
    list->pnext = NULL;
    (*prear)->pnext = list;
    (*prear) = (*prear)->pnext;
}

List ListOrder(List list)
{
    int cnt = 0;
    List listOrder, rear, temp;
    listOrder = (List)malloc(sizeof(Node));
    listOrder->next = list->next;
    listOrder->pnext = NULL;
    rear = listOrder;
    for (temp = list; temp->pnext;)
    {
        if (temp->pnext->pre == rear->next)
        {
            rear->pnext = temp->pnext;
            temp->pnext = rear->pnext->pnext;
            rear->pnext->pnext = NULL;
            rear = rear->pnext;
            cnt++;
            temp = list;
        }
        else
            temp = temp->pnext;
    }
    rear->next = -1;
    listOrder->data = cnt;
    return listOrder;
}

void ListReverse(List list, int n, int k)
{
    if (n < k)
        return;
    List head, rear, temp;
    head = list->pnext;
    rear = head->pnext;

    for (int i = 1; i < k; i++)
    {
        temp = rear->pnext;
        rear->pnext = head;
        rear->next = head->pre;
        head = rear;
        rear = temp;
    }
    rear = list->pnext;
    rear->pnext = temp;
    list->pnext = head;
    list->next = head->pre;
    n = n - k;
    if (n)
        rear->next = temp->pre;
    else
        rear->next = -1;

    ListReverse(rear, n, k);
}

List ListRead()
{
    List list, rear;
    list = (List)malloc(sizeof(Node));
    list->pnext = NULL;
    rear = list;
    int first, n, k, pre, data, next;
    scanf("%d %d %d", &first, &n, &k);
    while (n--)
    {
        scanf("%d %d %d", &pre, &data, &next);
        ListAttach(&rear, pre, data, next);
    }
    list->next = first;
    list = ListOrder(list);
    n = list->data;
    if (k != 0 && k != 1)
        ListReverse(list, n, k);

    return list;
}

void ListPrint(List list)
{
    List p = list->pnext;
    while (p->next != -1)
    {
        printf("%05d %d %05d\n", p->pre, p->data, p->next);
        p = p->pnext;
    }
    printf("%05d %d %d\n", p->pre, p->data, p->next);
}

int main()
{
    List list;
    list = ListRead();
    ListPrint(list);
    return 0;
}
