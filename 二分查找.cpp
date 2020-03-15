#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
	List L;
	ElementType X;
	Position P;

	L = ReadInput();
	scanf("%d", &X);
	P = BinarySearch( L, X );
	printf("%d\n", P);

	return 0;
}

Find(Position start,Position final,List L,ElementType X)
{
	Position mid=(start+final)/2;
	if(start>final)
	{
		return NotFound;
	}
	else if(X==L->Data[mid])
	{
		return mid;
	}
	else if(X>L->Data[mid])
	{
		Find(mid+1,final,L,X);
	}
	else if(X<L->Data[mid])
	{
		Find(start,mid-1,L,X);
	}
}
Position BinarySearch2( List L, ElementType X )//递归做法 
{
	Position start=1;
	Position final=L->Last;
	
	return Find(start,final,L,X);
}


Position BinarySearch1( List L, ElementType X )//循环做法 
{
	Position Find=NotFound;
	Position start=1;
	Position final=L->Last;
	Position mid;

	while(start<=final)
	{
		mid=(start+final)/2;
		if(X==L->Data[mid])
		{
			Find=mid;break;
		}
		else if(X>L->Data[mid])
		{
			start=mid+1;
		}
		else if(X<L->Data[mid])
		{
			final=mid-1;
		}
	}

	return Find;
}


