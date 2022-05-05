#include<stdio.h>
#include<string.h>
void myprintf(char *msg)
{
	if(msg!=NULL)
	printf("Message : %s \n",msg);
}
int main()
{
	char buff[]="linux";
	myprintf(NULL);
	return 0;
}
