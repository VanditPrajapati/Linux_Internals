#include<stdio.h>
#include<pthread.h>

pthread_t tid;
void * thread1(void *ard)
{
printf("Newly created Thread is executing \n");
return NULL;
}
int main(void)
{
int ret =pthread_create(&tid,NULL,thread1,NULL);
if(ret)
printf("Thread is not created \n");
else
{
pthread_join(tid, NULL);
printf("Thread is created \n");
}
//sleep(2);

return(0);
}
