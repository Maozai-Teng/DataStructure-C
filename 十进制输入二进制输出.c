#include <stdio.h>
#include <stdlib.h>

int main()
{    
    int number;
    printf("Input:");
    scanf("%d",&number);
    unsigned int mask=1u<<(sizeof(int)*8-1);
    for(;mask;mask>>=1)
    {
    	printf("%d",number&mask?1:0);
	}
	printf("\n");

    return 0;
}

