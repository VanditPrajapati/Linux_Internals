#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

main()
{
	size_t i;
	const int alloc_size=32; //32*1024*1024
	char* mem=malloc(alloc_size);
	mlock(mem,alloc_size);
	
	for(i=0;i<alloc_size;i++)
	mem[i]='#';
	printf("allocated memory initialized with = %s\n",mem);
	munlock(mem,alloc_size);


}
