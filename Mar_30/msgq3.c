//Code for getting information related to msg queue

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define KEY 8979

int main()
{
	int qid;
	struct msqid_ds buf;
	qid=msgget(32, IPC_CREAT|0644);
	printf("qid: %d\n", qid);
	msgctl(qid, IPC_STAT, &buf);
	printf("Here are the details of the quque\n");
	printf("No. of msgs in queue: %hi\n", buf.msg_qnum);
	printf("Max no. of bytes in a q %hi\n", buf.msg_qbytes);
}
