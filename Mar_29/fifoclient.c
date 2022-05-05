#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main()
{
	printf("Client process writing\n");
	
	char clientmsg[]="Linux system Kernel Programming";
	
	//Open FIFO for write
	int fd=open("cli_ser_fifo1",O_WRONLY);
	if(fd==-1)
	{
		perror("Cannot Open FIFO");
		return EXIT_FAILURE;
	}
	
	write(fd, clientmsg, strlen(clientmsg));
	
	close(fd);
	return 0;
}
