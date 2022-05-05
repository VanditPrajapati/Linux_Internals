#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// Declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


// Thread function
void *foo(void *arg)
{
/*char *str = (char *)arg;
printf("Thread task called by = %s\n",str);
*/
int *done=(int*)arg;
if(done==2)
done=3;

// acquire a lock
pthread_mutex_lock(&lock);
if(done==1)
{
// let's wait on condition variable cond1
printf("Waiting on condition variable cond1\n");
pthread_cond_wait(&cond1,&lock);
}
else
{
// let's signal condition variable cond1
printf("Signaling condition variable cond1\n");
pthread_cond_signal(&cond1);
}
pthread_mutex_unlock(&lock);

if(done==3)
{
printf("I am thread2\n");
}
printf("Returning thread \n");

return NULL;
}

int main()
{
	pthread_t tid1,tid2;
	int done=1;
	
	pthread_create(&tid1,NULL,foo,(void*)done);
	
	sleep(1);
	
	done = 2;
	
	pthread_create(&tid2,NULL,foo,(void*)done);
	
	pthread_join(tid2,NULL);
	
	return 0;

}
