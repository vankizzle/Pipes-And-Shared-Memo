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
char tmpchar;

fd = open(myfifo, O_RDWR);
  
while(read(fd, &tmpchar, 1)){
  write(STDOUT_FILENO, &tmpchar, 1);
}
write(STDOUT_FILENO, "\n", 1);
close(fd);
return 0;
}
