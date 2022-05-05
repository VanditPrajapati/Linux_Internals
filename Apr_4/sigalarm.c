#include<signal.h>

void sighand(int signum)
{
	printf("I have to wake up my boss now\n");
}

main()
{
	signal(SIGALRM, sighand);
	alarm(5);
	while(1);
}
