#include<stdio.h>
void main(int argc,char *argv[])
{
int i;
printf("\n File name : %s\n",argv[0]);

printf("\n Total number of arguments : %d\n",argc);

for(int i=1;i<argc;i++)
{
printf("%s ",argv[i]);
}
printf("\n");
}
