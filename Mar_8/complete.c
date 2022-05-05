#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int fd1,fd2,fd3,len;
char read_buf1[60];
char write_buf1[60]="Linux kernel new program";
fd1=open("abc1.txt",O_CREAT | O_RDWR,777);
printf("ABC1 file opened : %d \n",fd1);
len=write(fd1,write_buf1,60);
printf("File written of number : %d \n",len);


lseek(fd1,0,SEEK_SET);

read(fd1,read_buf1,len);
printf("Data from buffer read : %s\n",read_buf1);

lseek(fd1,6,SEEK_SET);

read(fd1,read_buf1,6);
printf("Data from buffer read : %s\n",read_buf1);

lseek(fd1,-5,SEEK_CUR);

read(fd1,read_buf1,len);
printf("Data from buffer read : %s\n",read_buf1);

lseek(fd1,-55,SEEK_END);

read(fd1,read_buf1,len);
printf("Data from buffer read : %s\n",read_buf1);
//printf("return value = %d \n",len);
close(fd1);
}
