#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int fd;
	
	//FIFO File path
	//char *newfifo="/tmp/newfifo";
	
	mkfifo("newfifo",0666);
	
	char arr1[100], arr2[100];
	
	while(1)
	{
		//Open FIFO for write only
		fd=open("newfifo",O_WRONLY);
		
		//Take an input arr2ing from user
		//100 is maximum length
		fgets(arr2, 100, stdin);
		
		//Write the input arr2ing on FIFO
		//and close it
		write(fd, arr2, strlen(arr2)+1);
		close(fd);
		
		//Open FIFO for read-only
		fd=open("newfifo",O_RDONLY);
		
		//Read from FIFO
		read(fd, arr1, sizeof(arr1));
		
		//Print the real message
		printf("User2: %s\n", arr1);
		close(fd);
	}
	return 0;
}
