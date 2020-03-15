#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct PolyNode
{
	int coef;
	int exp;
	struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

void Attach(int coef, int exp, Polynomial *pRear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->exp = exp;
	P->link = NULL;
	(*pRear)->link = P;
	(*pRear) = P;
}

int Compare(int exp1, int exp2)
{
	while (exp1 == exp2)
		return 0;
	while (exp1 > exp2)
		return 1;
	while (exp1 < exp2)
		return -1;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;	//前后标记，方便使用
	while (P1 && P2) //两边都有进行合并
	{
		switch (Compare(P1->exp, P2->exp))
		{
		case 1:
			Attach(P1->coef, P1->exp, &rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef, P2->exp, &rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum)
				Attach(sum, P1->exp, &rear);
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	}
	//未处理完的放结尾
	for (; P1; P1 = P1->link)
		Attach(P1->coef, P1->exp, &rear);
	for (; P2; P2 = P2->link)
		Attach(P2->coef, P2->exp, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}

Polynomial PolyMult(Polynomial P1, Polynomial P2)
{
	if (!(P1 && P2))
		return NULL;
	Polynomial front, rear, t1, t2, temp;
	int coef, exp;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	t1 = P1;
	t2 = P2;
	while (t2)
	{
		Attach(t1->coef * t2->coef, t1->exp + t2->exp, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = P2;
		rear = front;
		while (t2)
		{
			coef = t1->coef * t2->coef;
			exp = t1->exp + t2->exp;
			while (rear->link && rear->link->exp > exp)
				rear = rear->link;
			if (rear->link && rear->link->exp == exp)
			{
				if (rear->link->coef + coef)
					rear->link->coef += coef;
				else
				{
					temp = rear->link;
					rear->link = temp->link;
					free(temp);
				}
			}
			else
			{
				temp = (Polynomial)malloc(sizeof(struct PolyNode));
				temp->coef = coef;
				temp->exp = exp;
				temp->link = rear->link;
				rear->link = temp;
				rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	temp = front;
	front = front->link;
	free(temp);
	return front;
}

Polynomial ReadPoly()
{
	int N, coef, exp;
	Polynomial P, Rear, Temp;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;

	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d", &coef, &exp);
		Attach(coef, exp, &Rear);
	}
	Temp = P;
	P = P->link;
	free(Temp);
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;
	if (!P)
	{
		printf("0 0\n");
		return;
	}
	while (P)
	{
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->exp);
		P = P->link;
	}
	printf("\n");
}

int main(void)
{
	Polynomial P1, P2, PM, PA;
	//读入多项式
	P1 = ReadPoly();
	P2 = ReadPoly();

	//乘法并输出
	PM = PolyMult(P1, P2);
	PrintPoly(PM);

	//加法并输出
	PA = PolyAdd(P1, P2);
	PrintPoly(PA);

	return 0;
}
