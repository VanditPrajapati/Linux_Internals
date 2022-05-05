#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf
{
	long mtype;
	char data[512];
};

int main(int argc, char *argv[])
{
	int qid;
	struct msqid_ds buf;

	struct msgbuf m;
	
	qid=msgget(32, IPC_CREAT|0644);
	printf("Mesaage Queue ID: %d\n", qid);
	
	m.mtype=atoi(argv[1]);
	strcpy(m.data, argv[2]);
	msgsnd(qid, &m, strlen(m.data)+1, 0);
	
	msgctl(qid, IPC_STAT, NULL);
	printf("No. of messages: %hi\n", buf.msg_qnum);
	printf("No. of bytes in message queue: %hi\n", buf.msg_cbytes);
	printf("Max no. of bytes in message queue: %hi\n", buf.msg_qbytes);
	
	msgctl(qid, IPC_RMID, NULL);
}
