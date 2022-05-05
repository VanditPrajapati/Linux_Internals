#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff_comm[5];
	strcpy(buff_comm,"ls -l");
	
	printf("system() library function uses fork() to create a child process\n");
	printf("Child process executes execl() which loads and run new program provided by system() argument\n");
	int r=system(NULL);
	r=system(buff_comm);
	printf("system  return value : %d\n",r);
	return 0;
}
