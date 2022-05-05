#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
void call1(void)
{
printf("Callback 1 function \n");
}
void call2(void)
{
printf("Callback 2 function \n");
}
void call3(void)
{
printf("Callback 3 function \n");
}


int main()
{
printf("Registering Callback1 \n");
atexit(call1);
printf("Registering Callback2 \n");
atexit(call2);
printf("Registering Callback3 \n");
atexit(call3);
printf("Main function terminated\n");
exit(0);
//_exit(0);
}
