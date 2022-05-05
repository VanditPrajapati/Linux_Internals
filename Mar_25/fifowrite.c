#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	char s[20];
	int fd;
	
	mkfifo("newfifo2", 0044);
	
	perror("mkfifo");
	
	printf("Before open()..\n");
	fd=open("newfifo2",O_WRONLY);
	printf("After open()..\n");
	
	printf("Enter data..\n");
	scanf("%s",s);
	write(fd, s, strlen(s)+1);
	
	read(fd, s, sizeof(s));
	printf("Data: %s\n",s);
	return 0;
}
