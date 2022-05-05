#include<stdio.h>
#include<string.h>



void mymemcopy(char *src, char *dest, int count)
{
int i;



for(i=0;i<count;i++)
{
*dest = *src;
dest++;
src++;
}
}



int main()
{
char str1[10]="linuxnew";
char str2[10];

mymemcopy(str1,str2,10);

printf("String in str2 = %s\n",str2);

return 0;
}
