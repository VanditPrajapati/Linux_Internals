#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid1,tid2,tid3,tid4;
void * thread1(void *ard)
{
printf("Newly created Thread1 is executing \n");
return NULL;
}
void * thread2(void *arg)
{
printf("Newly created Thread2 is executing \n");
return NULL;
}
void * thread3(void *arg)
{
printf("Newly created Thread3 is executing \n");
return NULL;
}
void * thread4(void *arg)
{
printf("Newly created Thread4 is executing \n");
return NULL;
}
int main(void)
{
pthread_create(&tid1,NULL,thread1,NULL);
pthread_create(&tid2,NULL,thread2,NULL);
pthread_create(&tid3,NULL,thread3,NULL);
pthread_create(&tid4,NULL,thread4,NULL);

/*pthread_join(tid1, NULL);
pthread_join(tid2, NULL);
pthread_join(tid3, NULL);
pthread_join(tid4, NULL);
//sleep(2);
*/
getchar();
return(0);
}
