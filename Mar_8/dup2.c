#include<stdio.h>
#include<fcntl.h>
void main()
{
int fd1,fd2,fd3,fd4;
fd1=open("abc1.txt",O_WRONLY,0777);
printf("FD1= %d \n",fd1);

//fd1=open("abc1.txt",O_WRONLY,0777);

fd3=dup(fd1);
printf("Dup of FD1 is FD3=%d \n",fd3);

fd3=dup2(fd1,4);
printf("FD3=%d \n",fd3);
}
