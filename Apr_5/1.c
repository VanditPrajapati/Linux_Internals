//This examplee demonstrates how to block signals using sigprocmask()
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
//Iterates through a list of signals and prints out which signals are in a signal set.void printsignalset(sigset_t *set)
void printSignalSet(sigset_t *set)
{
	const int sigList[] = { SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV };
	const char *sigNames[] = { "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV" };const int siglen = 8;
	for(int i=0;i<siglen;i++)
	{
		int ret = sigismember(set,sigList[i]);
		if(ret==-1)
		{
			perror("sigismember:");
			exit(EXIT_FAILURE);
		}
		else if(ret ==1)
		{
			printf("Signal %s=%d IS int he set.\n",sigNames[i],sigList[i]);
		}
		else
			printf("Signal %s=%d is not in the set.\n",sigNames[i],sigList[i]);
	}
}


int main(void)
{
	sigset_t set;
	if(sigprocmask(0,NULL,&set)!=0)
	{
		perror("Sigprocmask : ");
		exit(EXIT_FAILURE);
	}
	printf("---Initial signal mask for this process : ---\n");
	printSignalSet(&set);
//#if=1
	if(sigaddset(&set,SIGINT)!=0)
	{
		perror("Sigaddset :");
		exit(EXIT_FAILURE);
	}

//Tell OS that we want to mask our new set of signals---which now includes SIGINT
	if(sigprocmask(SIG_SETMASK,&set,NULL)!=0)
	{
		perror("Sigprocmask :");
		exit(EXIT_FAILURE);
	}
	
//Now ,SIGINT will be blocked
	printf("---NEW signal mask for the process :---\n");
	printSignalSet(&set);
	int secToSleep = 20;
	printf("Try CTRL+C. Try killing this program with kill-kill %d.GOing to sleep for %D seconds \n",getpid(),secToSleep);
	sleep(secToSleep);
	printf("Sleep returned.\n");
	printf("Removing all signals from mask.\n");
//sigemptyset(&set);
	sigfillset(&set);
	
	sigprocmask(SIG_SETMASK, &set, NULL);
	
	printSignalSet(&set);
	
	sleep(1);
	printf("Exited normally\n");
	return 0;
}


