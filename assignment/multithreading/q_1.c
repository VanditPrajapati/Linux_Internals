#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *fun()
{
	printf("Executing thread after main function termination\n");
	sleep(2);
	return 0;
}

int main()
{
	//Creating a thread object
	pthread_t tid;
	
	//Creating thread
	pthread_create(&tid,0,fun,0);
	
	printf("Main process executing\n");

	printf("Main function terminated\n");	
	
	//Pending thread executing
	pthread_exit(NULL);
	return 0;
}
