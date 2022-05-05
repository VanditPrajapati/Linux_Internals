#include<stdio.h>
#include<pthread.h>

//For running initialization code
pthread_once_t once=PTHREAD_ONCE_INIT;

//Initialization code
void *intialization_code()
{
	printf("Initialization code running\n");
	sleep(2);
}

//Thread Function
void *fun()
{
	pthread_once(&once,(void *)intialization_code);
	printf("Executing Thread\n");
	sleep(2);
	printf("Exiting from thread\n");
}

int main()
{
	pthread_t t;
	
	t=pthread_create(&t,NULL,fun,NULL);	
	pthread_exit(NULL);
	printf("Exiting from main program\n");
}
