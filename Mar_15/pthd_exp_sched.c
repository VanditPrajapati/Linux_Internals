#include<stdio.h>
#include<pthread.h>

void *Proc(void *param)
{
sleep(3);
return 0;
}

int main(int argc,char *argv[])
{
	pthread_attr_t Attr;
	pthread_t Id;
	int err,info;
	
	pthread_attr_init(&Attr);
	pthread_attr_getinheritsched(&Attr,&info);
	
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED :
			printf("INHERIT SCHED\n");
			break;
		
		case PTHREAD_EXPLICIT_SCHED :
			printf("Explicit Sched\n");
			break;
	}
	
	pthread_attr_setinheritsched(&Attr,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_getinheritsched(&Attr,&info);
	
	
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED :
			printf("\n INHERIT SCHED\n");
			break;
		
		case PTHREAD_EXPLICIT_SCHED :
			printf("Explicit Sched\n");
			break;
	}
	//pthread_create(&Id,&Attr,Proc,NULL);
	return (0);

}
