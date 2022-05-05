#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
void main()
{
int pid;
printf("Parent program\n");
pid=fork();
if(pid==0)
{
execl("/bin/ls","-lh",NULL);
printf("\nChild Process\n");
}
wait(0);
printf("Parent continue\n");
}
