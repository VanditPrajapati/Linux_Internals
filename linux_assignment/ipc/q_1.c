#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
	int id;
	char *addr;
	
	id=shmget(48, 250, IPC_CREAT|0644);
	
	printf("Shared Memory ID: %d\n",id);
	addr=shmat(id,0,0);
	printf("The address of shared area is: %p\n",addr);
	return 0;
}
