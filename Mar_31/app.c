#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf
{
	long mytype;
	char data[100];
};

int main(int argc, char *argv[])
{
	struct msgbuf v, v1;
	struct msqid_ds buf;
	int id,i;
	
	id=msgget(32, IPC_CREAT|0644);
	printf("ID: %d\n", id);
	
	v.mytype=atoi(argv[1]);
	strcpy(v.data, argv[2]);
	
	msgsnd(id, &v, strlen(v.data)+1, 0);
	
	
	msgrcv(id, &v, sizeof(v1), 20, 0);
	for(i=0;i<100;i++)
	{
		printf("%c", v1.data[i]);
	}
	printf("\n");
}
