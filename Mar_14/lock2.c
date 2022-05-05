#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar=5;
void *thread_inc(void *arg)
{
sharedVar++;
printf("After incr = %d\n",sharedVar);
}
void *thread_incr(void *arg)
{
sharedVar+=7;
printf("After incr = %d\n",sharedVar);
}

void *thread_dec(void *arg)
{
sharedVar--;
printf("After decr = %d \n",sharedVar);
}

int main()
{
pthread_t thread1,thread2,thread3;

printf("SharedVar = %d \n",sharedVar);

pthread_create(&thread1,NULL,thread_inc,NULL);
pthread_create(&thread3,NULL,thread_incr,NULL);
pthread_create(&thread2,NULL,thread_dec,NULL);



pthread_exit(NULL);
//pthread_join(thread1,NULL);
//pthread_join(thread3,NULL);
//pthread_join(thread2,NULL);


return 0;

}
