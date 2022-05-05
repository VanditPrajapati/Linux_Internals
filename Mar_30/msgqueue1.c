#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf
{
	long mtype;
	char data[512];
};

int main()
{
	struct msgbuf v;
	int id;
	
	long mt;
	char d[512];
	
	id=msgget(55, IPC_CREAT|0644);
	
	printf("id: %d\n", id);
	printf("Enter the type of data: ");
	scanf("%ld",&mt);
	printf("Enter the data: ");
	scanf("%s",d);
	v.mtype=mt;
	strcpy(v.data, d);
	msgsnd(id, &v, strlen(v.data)+1, 0);
	return 0;
}
