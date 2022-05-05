#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	printf("Server Listening\n");
	
	int code=mkfifo("cli_ser_fifo", 0764);
	if(code==-1)
	{
		perror("mkfifo returned an error - file may already exist\n");
	}
	
	int fd=open("cli_ser_fifo",O_RDONLY);
	if(fd==-1)
	{
		perror("Cannot OPEN FIFO for read\n");
		return 0;
	}
	
	printf("FIFO OPEN\n");
	
	//Read string (upto 100 characters)
	char serverrcv[100];
	memset(serverrcv, 0, 100);
	
	int res;
	char len;
	
	while(1)
	{
		res=read(fd, &len, 1);
		if(res==0)
		{
			break;
		}
		read(fd, serverrcv, len);
		printf("Server Received: %s\n", serverrcv);
	}
	
	printf("EOF Reached\n");
	
	close(fd);
	
	printf("FIFO Closed\n");
}
