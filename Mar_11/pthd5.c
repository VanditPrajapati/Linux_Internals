#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
void *printhello(void *threadid)
{
printf("\n Hello World! \n");
while(1);
}
int main()
{
pthread_t thread;
int rc,t=0;
printf("Creating thread \n");
rc=pthread_create(&thread,NULL,printhello,NULL);
printf("\n Thread ID : %u",thread);
sleep(4);
t=pthread_cancel(thread);
if(t==0)
printf("\n cancelled thread \n");
printf("\n Thread ID : %u\n",thread);
}
