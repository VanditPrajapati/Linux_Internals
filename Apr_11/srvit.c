//TCP SERVER Iterative: only one client is handled

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 8000
#define MAXSZ 100

int main()
{
	int sockfd;
	int newsockfd;
	
	struct sockaddr_in clientaddress; 
	struct sockaddr_in serveraddress;
	
	int n;
	char msg[MAXSZ];
	int clientaddresslength;
	
	sockfd=socket(AF_INET, SOCK_STREAM, 0);

	memset(&serveraddress, 0, sizeof(serveraddress));
	serveraddress.sin_family=AF_INET;
	serveraddress.sin_addr.s_addr=htonl(INADDR_ANY);
	serveraddress.sin_port=htons(PORT);
		
	bind(sockfd, (struct sockaddr *) &serveraddress, sizeof(serveraddress));
	
	listen(sockfd, 5);
	
	while(1)
	{
		printf("\n*******Server waiting for new client connection**********\n");
		clientaddresslength=sizeof(clientaddress);
		newsockfd=accept(sockfd, (struct sockaddr *) &clientaddress, &clientaddresslength);
		
		while(1)
		{
			n=recv(newsockfd,msg,MAXSZ,0);
			if(n==0)
			{
				close(newsockfd);
				break;
			}
			msg[n]=0;
			send(newsockfd,msg,n,0);
			printf("Receive and set: %s\n",msg);
		}
	}
	return 0;
}	
