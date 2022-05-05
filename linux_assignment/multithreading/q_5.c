#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
	int rc;
	int count=0;
	printf("Thread aquiring spinlock\n");
	rc=pthread_spin_lock(&slock);
	printf("Thread executing\n");
	printf("Unlocking spin lock\n");
	rc=pthread_spin_unlock(&slock);
	return NULL;
}

int main()
{
	int rc=0;
	pthread_t thread;
	
	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	
	printf("Main function aquiring spin lock\n");
	rc=pthread_spin_lock(&slock);

	rc=pthread_create(&thread,NULL,spinlockthread,(int *)1);

	printf("Executing main function\n");
	sleep(5);

	printf("Main unlocking spin lock\n");
	rc=pthread_spin_unlock(&slock);

	if(rc==0)
		printf("\nMain Thread Successfully unlocked \n");
	else
		printf("\nMain Thread Successdully unlocked \n");


	printf("Main function waiting for thread to complete execution\n");	
	rc= pthread_join(thread,NULL);
	printf("Main completed \n");
	return 0;
}
