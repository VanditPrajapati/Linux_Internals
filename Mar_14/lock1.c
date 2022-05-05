#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void buggy()
{
int *p;
int i;
p=(int *)malloc(sizeof(int)*5);
printf("Malloc checking : Addr=%08x and Size=%d\n",p,sizeof(int)*5);

for(i=0;i<5;i++)
{
*p=100;
printf("Value at ptr p=%d\n",*p);
p++;
}
}
int main()
{
buggy();
return 0;

}
