#include<stdio.h>
#include<stdlib.h>



void buggy()
{
int *intptr;

intptr=(int *)malloc(sizeof(int));

*intptr=100;
printf("Value of ptr intptr: %d\n",(*intptr));
free(intptr);
*intptr=99;
}



void buggy1()
{
int *intptr1;

*intptr1=100;
free(intptr1);
}



void buggy2()
{
int *intptr2;
*intptr2=NULL;
free(intptr2);
}



int main()
{
buggy();
buggy1();
buggy2();
return 0;
}
