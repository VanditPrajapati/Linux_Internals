#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

void* Proc(void* param)
{
printf("I am original\n");
sleep(2);
return 0;
}

int main()
{
pthread_attr_t Attr,attr;
pthread_t Id;
void *stk;
size_t siz;
int err;

size_t my_stksize=0x30000000;
void * my_stack;

pthread_attr_init(&Attr);

pthread_attr_getstacksize(&Attr,&siz);
pthread_attr_getstackaddr(&Attr,&stk);

printf("Default : Addr=%08x default size= %d \n",stk,siz);

my_stack=(void*)malloc(my_stksize);

pthread_attr_setstack(&Attr,my_stack,my_stksize);
pthread_create(&Id,&Attr,Proc,NULL);

printf("newly defined stack : Addr=%08x and Size=%d \n",stk,siz);

sleep(3);
return (0);
}





