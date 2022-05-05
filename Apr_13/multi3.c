//Using select() system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>

main()
{
	int fd1, fd2;
	
	fd_set read_set, write_set, except_set;
	char buf[10];
	
	struct timeval timeout;
	
	int n;
	timeout.tv_sec=90;
	
	fd1=open("./read1", O_RDWR);
	fd2=open("./dup", O_RDWR);
	
	FD_ZERO(&read_set);
	
	
	FD_SET(fd1, &read_set);
	FD_SET(fd2, &read_set);
	
	n=select(FD_SETSIZE, &read_set, NULL, NULL, &timeout);
	
	if(n<0)
	{
		perror("select ");
		exit(1);
	}
	
	//Test whether fd1 is ready or not
	if(FD_ISSET(fd1, &read_set))
	{
		printf("Reading from fd1 (read1)\n");
		n=read(fd1, buf, 10);
		printf("Read %d from read1\n", n);
	}
	
	//Test whether fd2 is ready or not
	if(FD_ISSET(fd2, &read_set))
	{
		printf("Reading from fd2 (dup)\n");
		n=read(fd2, buf, 10);
		printf("Read %d from dup\n", n);
	}		
}
