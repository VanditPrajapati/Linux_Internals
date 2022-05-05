//Detaching : The pthread_detach() routine can be used to explicitly detach a thread even though it was created a joinable


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NUM_THREADS 3
int i=0;
void *myfun(void *null)
{
i++;
int result=0;
result+=i*1000;
printf("result=%d\n",result);

pthread_exit(NULL);
}

int main(int argc,char *argv[])
{

pthread_t thread[NUM_THREADS];
pthread_attr_t attr;
//const pthread_attr_t attr1;
int rc,t,status,detach_state;

//Initalize and set thread detached sttribute
pthread_attr_init(&attr); //initz attr obj

pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

for(t=0;t<NUM_THREADS;t++)
{
printf("Creating thread %d \n",t);
pthread_create(&thread[t],&attr,myfun,NULL);
}

//Get the default set by us
pthread_attr_getdetachstate(&attr,&detach_state);
printf("\nDetach State : %d\n",(int *)detach_state);

//pthread_attr_destroy(&attr);

printf("\n Exiting from main Thread \n");
pthread_exit(NULL);
return 0;

}
