#include<stdio.h>
#include<string.h>

void main()
{
	char buf1[10]="Mad",buf2[10]="Madam";
	int ret;
	
	memcpy(buf1,buf2,5);
	
	printf("Buf2 - %s\n",buf2);
	printf("Buf1 - %s\n",buf1);
	
	char buf3[10]="ABCDEFGH";
	memmove(buf1,buf3,7);
	
	printf("Buf3 - %s\n",buf3);
	printf("Buf1 - %s\n",buf1);
}	
