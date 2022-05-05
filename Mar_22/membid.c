#include<stdio.h>
#include<string.h>

struct A
{
	int roll;
	char name[40],gen;
	float height;
	char x;
};

int main()
{
	struct A first;
	printf("\n Size of struct A %3d\n",sizeof(first));
}
