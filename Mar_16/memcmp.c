#include<stdio.h>
#include<string.h>

void main()
{
	char buf1[10],buf2[10];
	int ret;
	
	memcpy(buf1,"Mad ",5);
	memcpy(buf2,"Madam",5);
	
	ret = memcmp(buf1,buf2,5);
	//printf("%s\n",buf1);
	//printf("%d\n",ret);
	if(ret>0)
		printf("Buf1 is greater than Buf2\n");
	else if(ret<0)
		printf("Buf1 is less than Buf2\n");
	else
	printf("Both are equal");
	
}
