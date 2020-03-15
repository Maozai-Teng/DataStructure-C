#include <stdio.h>
#include <string.h>

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int *p = (int *)(&array);
	int (*q)[10] = &array;
	int (*m)[1]=&array[1];
	int *n=&array[1];

	printf("m:\t\t%p\n",m);
	printf("*m:\t\t%p\n",*m);
	printf("**m:\t\t%p\n",**m);
	printf("&m:\t\t%p\n\n",&m);

	printf("n:\t\t%p\n",n);
	printf("*n:\t\t%p\n",*n);
	printf("&n:\t\t%p\n\n",&n);

	printf("sizeof(&p):\t%d\n",sizeof(&p));
	printf("sizeof(int):\t%d\n",sizeof(int));
	printf("sizeof(int*):\t%d\n\n",sizeof(int*));

	printf("p:\t\t%p\n",p);
	printf("*p:\t\t%p\n",*p);
	printf("&p:\t\t%p\n\n",&p);

	printf("p+1:\t\t%p\n",p+1);
	printf("(*p)+1:\t\t%p\n",(*p)+1);
	printf("*(p+1):\t\t%p\n",*(p+1));
	printf("(&p)+1:\t\t%p\n\n",(&p)+1);

	printf("q:\t\t%p\n",q);
	printf("*q:\t\t%p\n",*q);
	printf("&q:\t\t%p\n\n",&q);

	printf("q+1:\t\t%p\n",q+1);
	printf("(*q)+1:\t\t%p\n",(*q)+1);
	printf("*(q+1):\t\t%p\n",*(q+1));
	printf("(&q)+1:\t\t%p\n\n",(&q)+1);

	printf("array:  \t%p\n",array);
	printf("&array[0]:\t%p\n",&array[0]);
	printf("*array: \t%p\n",*array);
	printf("&array: \t%p\n\n",&array);

	printf("array+1:\t%p\n",array+1);
	printf("&array[0]+1:\t%p\n",&array[0]+1);
	printf("(*array)+1:\t%p\n",(*array)+1);
	printf("*(array+1):\t%p\n",*(array+1));
	printf("&array+1:\t%p\n\n",&array+1);


	return 0;
}
