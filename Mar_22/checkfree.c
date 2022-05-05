//After freeing a ptr we are again dereferencing it.

#include<stdio.h>
#include<stdlib.h>

void buggy()
{
int *intptr;
int i;
intptr=(int *)malloc(sizeof(int)*5);

*intptr=100;
printf("Value at ptr intptr = %d\n", (*intptr));
free(intptr);
*intptr=99;
}


int main()
{
buggy();
return 0;
}
