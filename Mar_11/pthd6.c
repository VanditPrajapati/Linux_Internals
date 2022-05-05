#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

static void* threadfun(void *arg)
{
char *s=(char *)arg;
printf("%s \n",s);
sleep(5);
return (void*)strlen(s);
return 0;
}

int main(int argc,char *argv[])
{
pthread_t t1;
void *res;
int s;
pthread_create(&t1,NULL,threadfun,"Hello World");
printf("Main Message \n");
sleep(3);
pthread_join(t1,&res);
printf("Thread returned %ld\n",(long)res);
exit(0);

}
