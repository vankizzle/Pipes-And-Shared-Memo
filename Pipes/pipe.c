#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){

int fd;
char buff[256];
char* myfifo = "/tmp/myfifo";
mkfifo(myfifo,0666);
printf("Run Reader process to read the FIFO File\n");
fd = open(myfifo,O_WRONLY);
write(fd,"This is a test",sizeof("This is a test"));
close(fd);
unlink(myfifo);



return 0;
}
