#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#define MAX_BUF 256

int main(){

int fd;
char* myfifo = "/tmp/myfifo";
char buff[MAX_BUF];

fd = open(myfifo, O_RDWR);
read(fd,buff,MAX_BUF);
printf("Writer:%s\n",buff);
close(fd);
return 0;
}
