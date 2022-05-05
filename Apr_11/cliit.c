//TCP SERVER Iterative: only one client is handled

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100

int main()
{
	int sockfd;
	int newsockfd;
	
	char msg1[MAXSZ];
	char msg2[MAXSZ];
	
	struct sockaddr_in clientaddress; 
	struct sockaddr_in serveraddress;
	
	int n;
	char msg[MAXSZ];
	int clientaddresslength;
	
	sockfd=socket(AF_INET, SOCK_STREAM, 0);

	memset(&serveraddress, 0, sizeof(serveraddress));
	serveraddress.sin_family=AF_INET;
	serveraddress.sin_addr.s_addr=inet_addr(SERVER_IP);
	serveraddress.sin_port=htons(PORT);
		
	connect(sockfd, (struct sockaddr *) &serveraddress, sizeof(serveraddress));
	
	while(1)
	{
		printf("\nEnter message to send to server:\n");
		fgets(msg1,MAXSZ,stdin);
		if(msg1[0]=='#')
			break;
		
		n=strlen(msg1)+1;
		send(sockfd,msg1,n,0);
		
		n=recv(sockfd,msg2,MAXSZ,0);
		
		printf("Receive message from server: %s\n",msg2);
	}
	return 0;
}	
