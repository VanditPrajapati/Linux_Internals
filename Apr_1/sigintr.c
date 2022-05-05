#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("Interrupt signal recorded but no termination on CTRL+C\n");
	signal(SIGINT, SIG_DFL);
}

int main()
{
	int i;
	
	signal(SIGINT, sighand);
	//signal(SIGINT, SIG_DFL);
	
	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
