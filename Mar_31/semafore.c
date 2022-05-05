#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int get_semaphore(void);
int release_semaphore(void);
int sem_id;

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

struct sembuf sem_op;
union semun sem_union;

int main()
{
	int i, j;
	sem_id=semget((key_t)1234, 1, 0666|IPC_CREAT)
