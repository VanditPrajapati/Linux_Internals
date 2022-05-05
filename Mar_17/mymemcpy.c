#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

void *mymemcpy(void *src,void *dst,int n)
{
long *s=(long*)src;
long *d=(long*)dst;
for(int i=0;i<n;i++)
{
d[i]=s[i];
}
printf("Copied");
}
int main()
{
char buf1[10]="ABCDEFGH";
char buf2[10];
mymemcpy(buf1,buf2,5);
return 0;
}
