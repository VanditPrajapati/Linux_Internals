#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *process(void *arg)
{
pthread_detach(pthread_self());
printf("Sleeping 2 secs \n");
sleep(2);
printf("SLept 2 secs\n");
}

void main()
{
pthread_t tid;
int errno=pthread_create(&tid,NULL,process,NULL);
if(errno)
perror("pthread_create : ");
pthread_exit(NULL);

}
