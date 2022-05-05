#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_t tid;

void* threadfun(void *arg)
{
pid_t pid;
pthread_t tid;
pid=getpid();
tid=pthread_self();

printf("pid : %u and tid : %u \n",(unsigned int)pid,(unsigned int)tid);
}
int main(void)
{
int err;
err= pthread_create(&tid,NULL,threadfun,"Hello Vandit");
if(err!=0)
printf("can't create thread : %s \n",strerror(err));
while(1);

exit(0);

}
