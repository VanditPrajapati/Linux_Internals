#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
void main()
{
execl("/home/vandit/Desktop/10-3-22/cmd1","./cmd1","aa","bb","cc",NULL);
printf("ABC \n");
}
