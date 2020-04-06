#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node *List;
typedef struct _Node
{
    int pre;
    int data;
    int next;
} Node;

void NodeOrder(Node node[])
{
    int cnt = 0, i, flag = 0;
    int n = node[0].data;
    Node temp = {-2, -2, -2};
    for (i = 0; i <= n; i++)
    {
        flag = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (node[i].next == node[j].pre)
            {
                temp = node[i + 1];
                node[i + 1] = node[j];
                node[j] = temp;
                flag = 1;
                cnt++;
                break;
            }
        }
        if (!flag)
            break;
    }
    node[0].data = cnt;
    node[i].next = -1;
}

void NodeReverse(Node node[])
{
    int k = node[0].pre;
    int n = node[0].data;
    int cnt = n / k;
    Node temp = {-2, -2, -2};
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 1; j <= k / 2; j++)
        {
            temp = node[i * k + j];
            node[i * k + j] = node[(i + 1) * k - j + 1];
            node[(i + 1) * k - j + 1] = temp;
        }
    }
    if (!(n % k))
        node[n].next = -1;
}

void NodeReNumber(Node node[])
{
    int n = node[0].data;
    for (int i = 1; i < n; i++)
        node[i].next = node[i + 1].pre;
}

void NodeRead(Node node[])
{
    int first, n, k, pre, data, next;
    scanf("%d %d %d", &first, &n, &k);
    node[0].pre = k;
    node[0].data = n;
    node[0].next = first;
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &node[i].pre, &node[i].data, &node[i].next);

    NodeOrder(node);
    if (k != 0 && k != 1)
        NodeReverse(node);

    NodeReNumber(node);
}

void NodePrint(Node node[])
{
    int i;
    for (i = 1; node[i].next != -1; i++)
        printf("%05d %d %05d\n", node[i].pre, node[i].data, node[i].next);

    printf("%05d %d %d\n", node[i].pre, node[i].data, node[i].next);
}

int main()
{
    Node node[100005];
    NodeRead(node);
    NodePrint(node);

    return 0;
}
