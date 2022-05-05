#include<stdio.h>
#include<string.h>

void main()
{
	const char str[]="Linuxkernel.com";
	const char ch='.';
	char *ret;

	printf("String before memchr is %s\n",str);

	ret=memchr(str,ch,strlen(str));
	
	printf("String after **%c** is - **%s**\n",ch,ret+1);

}
