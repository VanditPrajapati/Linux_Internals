#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	int sig_num;
	printf("Enter the pid of the process for which the signal need to be sent: ");
	scanf("%d",&pid);
	printf("Enter the signal that need to be sent: ");
	scanf("%d",&sig_num);
	kill(pid,sig_num);
	perror("sig_res");
}
