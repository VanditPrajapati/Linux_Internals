#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int i;
	printf("\n File Name  :%s\n",argv[0]);
	printf("Total Number of arguments : %d\n",argc);
	printf("Arguments Passed : ");
	for(i=0;i<argc;i++)
	printf("%s ",argv[i]);
	return 0;
}
