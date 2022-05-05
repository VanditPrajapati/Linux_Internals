#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int fds[2];

void parent_code()
{
	char *buf1="Vandit";
	char *buf2="Prajapati";
	close(fds[0]);	
	write(fds[1],buf1,6);
	write(fds[1],buf2,9);
	printf("End of Parent\n");
	sleep(2);
}


void child_code()
{
	char buf[100];	
	int n,i;
	close(fds[1]);
	n=read(fds[0],buf,100);
	printf("No of chars read = %d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\nEnd of child\n");
	sleep(2);
}





int main()
{
	int res,i;
	pid_t p;

	res=pipe(fds);
	//printf("\n %d \n",res);

	if(res==-1)
	{
		perror("pipe");
		exit(1);
	}
	p=fork();
	if(p==0)
	{
		child_code();
	}
	else
	{
		parent_code();
	}
	return 0;
}
