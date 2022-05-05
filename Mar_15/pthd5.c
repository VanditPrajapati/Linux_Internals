#include<string.h>
#include<stdio.h>
#include<pthread.h>

struct my_thread
{
	int tid;
	char msg[100];
};

void *hello(void *thobj)
{
	pthread_t t_id;
	struct my_thread *t1;
	t1=(struct my_thread *)thobj;
	t_id=pthread_self();
	printf("Thread ID : %u\n",t_id);
	printf("%d Thread Message : %s \n",t1->tid,t1->msg);
}

int main()
{
pthread_t thread1,t_id;
int rc;
	struct my_thread t1;
	t1.tid=4;
	strcpy(t1.msg,"I am a thread\n");
	
	t_id=pthread_self();
	printf("Main thread ID : %u\n",t_id);
	
	pthread_create(&thread1,NULL,hello,(void *)&t1);
	printf("Exit Main Thread \n");
	pthread_exit(NULL);
}
