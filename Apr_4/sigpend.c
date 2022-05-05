#include<stdio.h>
#include<signal.h>

void check_pending_sigs(sigset_t s)
{
	int i,res;
	for(i=1;i<5;i++)
	{
		res=sigismember(&s,i);
		if(res)
			printf("Signal %d is pending\n",i);
		else
			printf("Signal %d is not pending\n",i);
	}
}

void sighand(int no)
{
	printf("I am in sighandler\n");
}

main()
{
	//group of signals
	sigset_t s_set,s;
	
	//signal handler
	signal(2,sighand);
	
	//initializing signal set
	sigemptyset(&s_set);
	
	//signal added to group of signal set
	sigaddset(&s_set,2);
	perror("sig2");
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	perror("SIGMASK");
	printf("Send me signal one and see the effect now\n");
	getchar();
	getchar();
	sigpending(&s);
	check_pending_sigs(s);
	getchar();
	sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	printf("Now signals are unblocked\n");
	while(1);
}
