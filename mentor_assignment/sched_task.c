#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<stdlib.h>
#include<json-c/json.h>
#include<time.h>

pthread_t tid;

void *thread(void *arg)
{
	int l=0, u=9;
	int r_value;
	while(1)
	{
		// For generating random value
		srand(time(0));
		r_value = (rand()%(u-l+1))+l;
		
		//If random value is equal to the value obtain from file then terminate the thread
		if(r_value==arg)
		{
			pthread_exit(NULL);
		}
	}
	return NULL;
}


int main(void)
{
	int fd;
	char read_buf[1024];
	FILE *fp;

	struct json_object *parsed_json;
	struct json_object *value;

	//Defining the time object	
	time_t rawtime;
  	struct tm * timeinfo;
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
  	
  	//Running the code between 10am to 5pm
  	while((timeinfo->tm_hour > 10 & timeinfo->tm_min > 0) || (timeinfo->tm_hour < 4 & timeinfo->tm_min < 59))
	{
		//Reading the value from json file
		fp=fopen("value.json","r");
		fread(read_buf, 1024, 1, fp);
		fclose(fp);
	
		parsed_json = json_tokener_parse(read_buf);
		json_object_object_get_ex(parsed_json,"value",&value);
	
		value=json_object_get_int(value);
		printf("%d\n", value); 
	
		pthread_create(&tid, NULL, thread, value);
	
		pthread_join(tid, NULL);
	
		printf("Done\n");	
	}
}
