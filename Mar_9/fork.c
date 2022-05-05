#include<stdio.h>
#include<unistd.h>
void main()
{
int pid_1;
printf("Current process Pid=%d \n",getpid());
pid_1=fork();
if(pid_1==0)
{
printf("Child new PID =%d\n",getpid());
printf("new child parent ppid = %d\n ", getppid());
}
else
{
printf("Parent Pid=%d\n",getpid());
printf("Parents Parent PPID = %d \n",getppid());//bash
}

/*printf("S1\n");
fork();
fork();
printf("s2");
printf("s3");
*/


while(1);
}
