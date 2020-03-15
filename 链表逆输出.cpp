#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct _Node
{
	int data;
	struct _Node *pnext;
} Node, *PNode;

PNode reverse_re(PNode P) //甜仔的递归做法
{
	if (P == NULL || P->pnext == NULL)
		return P;
	PNode head = reverse_re(P->pnext);
	P->pnext->pnext = P;
	P->pnext = NULL;
	return head;
}

PNode reverse_cir(PNode P) //循环做法
{
	if (P == NULL || P->pnext == NULL)
		return P;
	PNode head, rear, temp;
	head = temp = P;
	rear = head->pnext;
	while (rear)
	{
		temp->pnext = rear->pnext;
		rear->pnext = head;
		head = rear;
		rear = temp->pnext;
	}
	return head;
}

PNode reverse_good(PNode P,int K) //循环做法(有头结点)
{
	if (P == NULL || P->pnext == NULL)
		return P;
	PNode head, rear, temp;
    int cnt=1;
	head = P->pnext;
	rear = head->pnext;
	while (cnt<K)
	{
		temp = rear->pnext;
		rear->pnext = head;
		head = rear;
		rear = temp;
        cnt++;
	}
    P->pnext->pnext=rear;
    P->pnext=head;
	return P;
}