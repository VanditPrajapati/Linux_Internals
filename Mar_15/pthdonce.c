#include<stdio.h>
#include<pthread.h>

pthread_once_t once=PTHREAD_ONCE_INIT;

void *myinit()
{
printf("\n I am in init function.\n");
}

void *mythread(void *i)
{
printf("\n I am in mythread : %d \n",(int *)i);
pthread_once(&once,(void *)myinit);
printf("\n Exit from mythread : %d \n",(int *)i);
}

int main()
{
pthread_t t1,t2,t3;
pthread_create(&t1,NULL,mythread,(void  *)1);
pthread_create(&t2,NULL,mythread,(void  *)2);
pthread_create(&t3,NULL,mythread,(void  *)3);
printf("\n Exit Main \n");
pthread_exit(NULL);
}
