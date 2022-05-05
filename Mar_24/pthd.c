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
printf("Entered thread %d, getting Spinlock \n",(int *)i);
rc=pthread_spin_lock(&slock);

printf("%d Thread lock the spin lock\n",(int *)i);
rc=pthread_spin_unlock(&slock);

printf("%d Thread unlock the spin lock\n",(int *)i);

printf("%d thread complete \n",(int *)i);
return NULL;
}

int main()
{
int rc=0;
pthread_t thread;
if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
perror("init");
printf("Main,get spin lock");
rc=pthread_spin_lock(&slock);

printf("Main,create the spin lock thread\n");
rc=pthread_create(&thread,NULL,spinlockthread,(int *)1);

printf("Main,wait a bit holding the spin lock\n");
sleep(5);

printf("Main,now unlock the spin lock\n");
rc=pthread_spin_unlock(&slock);
if(rc==0)
printf("\n Main Thread Successfully unlocked \n");
else
printf("\n Main Thread Successdully unlocked \n");

printf("Main, wait for the thread to end \n");
rc= pthread_join(thread,NULL);
//rc=pthread_spin_destroy(&slock);
printf("Main completed \n");
return 0;

}
