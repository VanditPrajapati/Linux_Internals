#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int p[2]; //p[0],p[1]
	
	pipe(p); //fd0--P[0]rd end and fd1--P[1]wt end
	printf("Read end of pipe: %d\t Write end of pipe: %d\n", p[0], p[1]);
	
	if(fork())
	{
		char s[20];
		printf("In parent enter data...\n");
		scanf("%s",s);
		write(p[1], s, strlen(s)+1);
		sleep(2);
	}
	else
	{
		char buff[25];
		printf("In child..\n");
		read(p[0], buff, sizeof(buff));
		printf("Child pro printing.. Data of the parent process..%s\n", buff);
		sleep(2);
	}
	
	return 0;
}
