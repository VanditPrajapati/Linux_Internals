#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>

void *fun()
{
	printf("Thread executing\n");
}

int main()
{
	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;
	
	//getting the scheduling policy and parameter
	ret=pthread_getschedparam(pthread_self(),&policy,&param);

	printf("Policy : %d\t Priority : %d\n",policy,param.sched_priority);
	
	//setting the Round Robin policy
	policy=SCHED_RR;
	//setting the priority as 3
	param.sched_priority=3;s
	//Setting the priority and policy
	ret=pthread_setschedparam(pthread_self(),policy,&param);
	
	//Getting the new values of priority and policy
	ret=pthread_getschedparam(pthread_self(),&policy,&param);
	printf("New Policy : %d\t New Priority : %d\n",policy,param.sched_priority);

	return 0;
}
