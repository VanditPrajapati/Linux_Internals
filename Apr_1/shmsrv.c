#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void togglecase(char *buf, int cnt);

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

union semun sem_union;

int main()
{
	int semid, shmid;
	char *pshm;
	struct sembuf smop;
	
	//Create semaphore set containing two semaphores
	semid=semget(MY_KEY, 1, 0000|IPC_CREAT);
	if(semid<0)
	{
		printf("Could not create semaphore\n");
		return (1);
	}
	else
		printf("Opened a semaphore ID is: %d\n",semid);
	
	//Set initial token count of both semaphore to zero
	semctl(semid, 0, SETVAL, 0);
	
	//Create a shared memory segment 
	shmid=shmget(MY_KEY, SHM_SIZE, 0660|IPC_CREAT);
	if(shmid<0)
	{
		printf("Could not create shared segment\n");
		return (2);
	}
	
	//Attach shared memory segment to PAS
	pshm=shmat(shmid, NULL, 0);
	if(!pshm)
	{
		printf("Could not attach shared memory segment\n");
		return(3);
	}
	
	while(1)
	{
		//Wait for token from semaphore
		smop.sem_num=0;
		smop.sem_op=-1;
		smop.sem_flg=0;
		
		semop(semid, &smop, 1);
		
		//Process the message available in shared memory
		printf("Get the semaphore\n");
		strcpy(pshm+256, pshm);
		togglecase(pshm+256, strlen(pshm+256));
		printf("Processed the request message and placed response\n");
		
		//Send token to semaphore
		smop.sem_num=1;
		smop.sem_op=1;
		smop.sem_flg=0;
		
		semop(semid, &smop, 1);
	}
}

void togglecase(char *buf, int cnt)
{
	int ii;
	for(ii=0;ii<cnt;ii++)
	{
		if(buf[ii]>='A' && buf[ii]<='Z')
		{
			buf[ii]+=0x20;
		}
		else if(buf[ii]>='a' && buf[ii]<='z')
		{
			buf[ii]-=0x20;
		}
	}
} 
