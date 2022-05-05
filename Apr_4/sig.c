#include<stdio.h>
#include<signal.h>

void sighand(int no)
{
	printf("CTRL+C Signal Handler\n");
}

main()
{
	//group of signals
	sigset_t s_set;
	
	//signal handler
	signal(2,sighand);
	
	//initializing signal set
	sigemptyset(&s_set);
	
	//signal added to group of signal set
	sigaddset(&s_set,2);
	perror("sig2");
	//sigaddset(&s_set,4);
	//perror("sig4");
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	perror("SIGMASK");
	printf("Send me signal one and see the effect now\n");
	getchar();
	//getchar();
	sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	printf("Now signals are unblocked\n");
	while(1);
}
