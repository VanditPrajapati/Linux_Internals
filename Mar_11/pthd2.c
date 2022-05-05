#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

static void* threadfun(void *arg)
{
char *s=(char*)arg;
printf("%s \n",s);
}


int main(int argc,char* argv[])
{
pthread_t t1;
void *res;
int s;
s= pthread_create(&t1,NULL,threadfun,"Hello Vandit");
printf("Main function \n");
sleep(1);
exit(0);
}

