//Implement fork in server to handle the client request 

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

void handleclient(int connfd)
{
	int n;
	char buf[200];
	n=read(connfd,buf,200);
	buf[n]='\0';
	printf("data recorded from client: %s\n",buf);
	printf("Requested handled by server: %d\n",getpid());
	write(connfd,"Good Bye", 8);
	exit(0);
}

main()
{
	int listfd, connfd, retval, n;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	char buf[10000];
	
	listfd=socket(AF_INET, SOCK_DGRAM, 0);
	if(listfd<0)
	{
		perror("sock:");
		exit(1);
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(8000);
	
	retval=bind(listfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval<0)
	{
		perror("bind:");
		exit(2);
	}
	
	printf("Socket bound to port 8000\n");
	clilen=sizeof(struct sockaddr_in);
	
	while(1)
	{
		printf("Before receive from\n");
		n=recvfrom(listfd, buf, 10000, 0, (struct sockaddr *) &cliaddr, &clilen);
		printf("Recorded %d bytes \n", n);
		buf[n]='\0';
		printf("MSG from client: %s\n", buf);
	}
}	
