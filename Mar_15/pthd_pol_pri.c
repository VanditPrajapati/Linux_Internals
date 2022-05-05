#include<stdio.h>
#include<pthread.h>

void *my(void *i)
{
	printf("\nI am in %d thread.\n",(int *)i);
}

main()
{
	pthread_t tid;
	struct sched_param param;
	int pri,pol,ret;
	
	ret=pthread_getschedparam(pthread_self(),&pol,&param);
	if(ret !=0)
	perror("getschedparam");
printf("\n -----------------------------------------------Main Thread -------------------------\nPolicy : %d\t Priority : %d\n",pol,param.sched_priority);
	pol=SCHED_FIFO;
	param.sched_priority=3;
	ret=pthread_setschedparam(pthread_self(),pol,&param);
	if(ret!=0)
	perror("getschedparam");
	
	ret=pthread_getschedparam(pthread_self(),&pol,&param);
	if(ret!=0)
	perror("getschedparam"); 
printf("\n -----------------------------------------------Main Thread -------------------------\nPolicy : %d\t Priority : %d\n",pol,param.sched_priority);


}
