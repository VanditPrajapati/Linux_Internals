#include<stdio.h>
#include<string.h>

void main()
{
	const char str[]="Linuxkernel.com";
	const char ch='#';

	printf("String before memset is %s\n",str);

	memset(str,ch,4);
	printf("String after memset is %s\n",str);

}
