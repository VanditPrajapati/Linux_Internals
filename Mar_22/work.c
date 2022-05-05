#include<stdio.h>
#include<stdlib.h>

void buggy()
{
int *intptr;
intptr=(int *)malloc(sizeof(int));

*intptr=100;
printf("Value at ptr intptr = %d\n", (*intptr));
free(intptr);
*intptr=99;
}

void buggy1()
{
int *ptr=99;
}

void buggy2()
{
void *p=NULL;
}


int main()
{
buggy();
buggy1();
buggy2();
return 0;
}
