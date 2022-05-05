#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
void main()
{
int pid;
int status;

printf("Parent =%d \n",getpid());

pid=fork();
if(pid==0)
{
sleep(5);
printf("Iam child with pid=%d",getpid());
exit(0);
}
printf("Parent reporting exit of child whose pid = %d \n",waitpid(pid,&status,0));
}
