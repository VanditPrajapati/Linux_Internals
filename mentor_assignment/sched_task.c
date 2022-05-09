#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<stdlib.h>
#include<json-c/json.h>
#include<string.h>
#include<pthread.h>

pthread_t tid;

void *thread(void *arg)
{
	int l=0, u=9;
	int r_value;
	int *v=(int *)arg;
	while(1)
	{
		// For generating random value
		srand(time(0));
		r_value = (rand()%(u-l+1))+l;
		
		//If random value is equal to the value obtain from file then terminate the thread
		if(r_value==v)
		{
			printf("Done\n");
			pthread_exit(NULL);
		}
	}
}

int main(void)
{
	int fd;
	char read_buf[1024];
	FILE *fp;
	
	int p=0, q=2, r=0;
	int t[20];
	
	int value=5;

	char *str;
	char s1[2];
	
	struct json_object *parsed_json;
	struct json_object *day;
	
	size_t ndays;
	

	//Reading from json file  	
  	fp=fopen("hours.json","r");
	fread(read_buf, 1024, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(read_buf);
	json_object_object_get_ex(parsed_json,"day",&day);
	ndays = json_object_array_length(day);
	char *s="WED";

	for (int i = 0; i < ndays; i++)
	{
	    json_object *d = json_object_array_get_idx(day, i);
	    json_object *d1 = json_object_object_get(d, s);
	    str = json_object_get_string(d1);
	}	
	
	printf("%s\n", str);
	
	//Storing the time string into array and then converting it into integer  
	for(p=0; str[p]!='\0'; p=p+1)
	{
		//memcpy(s1, &str[p], q);
		for(int c=0;c<2;c++)
		{
			s1[c]=str[p];
			p=p+1;
		}
		s1[2]='\0';
		t[r]=atoi(s1);
		r=r+1;
		//q=q+3;
	}
	
	
	for(int i=0;i<6;i++)
	{
		printf("%d\n", t[i]);
	} 

	  	
  	//Running the code between defined time 
  	while(1)
	{
		time_t rawtime;
  		struct tm * timeinfo;
  		time( &rawtime );
		timeinfo = localtime(&rawtime);
		printf("%02d:%02d:%02d\t", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
		
		if((timeinfo->tm_hour >= t[0] & timeinfo->tm_min > t[1]) && (timeinfo->tm_hour <= t[3] & timeinfo->tm_min < t[4] ))
		{		
			pthread_create(&tid, NULL, thread, (void *)value);
		
			pthread_join(tid, NULL);	
		}
		else
		{
			printf("Time execeeded\n");
			break;
		}
	}
}
