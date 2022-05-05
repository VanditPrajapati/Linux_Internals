#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
void main()
{
int fd1,fd2,pid_1;
fd1=open("xyz.txt",O_CREAT|O_RDWR,0777);
printf("FD1 = %d \n",fd1);
pid_1=fork();
if(pid_1==0)
{
execl("/bin/ls","ls","-lh",0);
exit(0);
}
else
{
fd2=wait(0);

printf("Wait return : %d \n",fd2);
printf("Parent process");
exit(0);
}
}
