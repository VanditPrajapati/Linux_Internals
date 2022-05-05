#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int fd1,fd2,fd3;
char write_buf[60]="Linux kernel new program";
fd1=open("abc.txt",O_CREAT | O_RDWR,777);
printf("ABC file opened : %d \n",fd1);
write(fd1,write_buf,60);
//printf("return value = %d \n",len);
close(fd1);


}
