#include<string.h>
#include<stdio.h>
#include<pthread.h>

struct information
{
	int tid;
	char a[100];
};

void *fun(void *inf)
{
	struct information *i;
	i=(struct information *)inf;
	printf("Thread Message :\ntid: %d\nMSG: %s\n",i->tid,i->a);
}

int main()
{
	pthread_t t1,tid;
	int rc;
	struct information inf;
	
	inf.tid=4;
	strcpy(inf.a,"My name is Vandit\n");
	
	//Passing structure object as argument
	pthread_create(&t1,NULL,fun,(void *)&inf);

	pthread_exit(NULL);	
	printf("Exit Main Thread \n");
}
