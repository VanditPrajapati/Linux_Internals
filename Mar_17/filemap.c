#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
int fd;
char *c;
struct stat file_info;
fd = open("kernel.txt",O_CREAT|O_RDWR,0777);
write(fd,"linux kernel technology",25);

fstat(fd,&file_info);
printf("File size is %ld\n",file_info.st_size);

c = mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
perror("mmap");

printf("%s\n",c);

strcpy(c,"Sankalp");

printf("%s\n",c);

munmap(c,file_info.st_size);
close(fd);

return 0;
}
