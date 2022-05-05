#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int fd1,fd2,fd3;
	char read_buf[60];
	fd1=open("abc.txt",O_CREAT | O_RDWR,777);	
	printf("ABC file opened : %d \n",fd1);
	if(fd1<0)
		printf("File is not opened or created\n");
	read(fd1,read_buf,60);	
	printf("%s",read_buf);
	//printf("return value = %d \n",len);
	close(fd1);
}
