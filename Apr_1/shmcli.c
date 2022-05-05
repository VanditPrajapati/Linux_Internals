#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256

int main()
{
	int semid, shmid;
	char *pshm;
	struct sembuf smop;
	semid=semget(MY_KEY, 1, 0000);
	
	if(semid<0)
	{
		printf("Could not create semaphore\n");
		return (1);
	}
	else
		printf("Opened a semaphore ID: %d\n", semid);
		
	shmid=shmget(MY_KEY, SHM_SIZE, 0660);
	if(shmid<0)
	{
		printf("Could not create shared memory segment\n");
		return (2);
	}
	
	pshm=shmat(shmid, NULL, 0);
	if(!pshm)
	{
		printf("Could not attach shared memory segment\n");
		return (3);
	}
	
	while(1)
	{
		printf("Client: Enter some request message to send to server\n");
		fgets(pshm, MSG_LEN, stdin);
		smop.sem_num=0;
		smop.sem_op=1;
		smop.sem_flg=0;
		semop(semid, &smop, 1);
		
		smop.sem_num=0;
		smop.sem_op=-1;
		smop.sem_flg=0;
		semop(semid, &smop, 1);
		puts(pshm+RESP_MSG_START);
	}
}
