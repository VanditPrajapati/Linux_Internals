#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	int qid;
	struct msqid_ds buf;
	qid=msgget(32, IPC_CREAT|0644);
	printf("qid: %d\n", qid);
	msgctl(qid, IPC_RMID, NULL);
}
