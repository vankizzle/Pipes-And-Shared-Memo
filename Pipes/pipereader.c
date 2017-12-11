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
  char c;
while(read(fd, &c, 1)){
  write(STDOUT_FILENO, &c, 1);
}
write(STDOUT_FILENO, "\n", 1);
close(fd);
return 0;
}
