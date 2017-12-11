#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#define MAX_BUFF 256
int main(){

int fd,i;
char buff[MAX_BUFF];
char* tmp;
tmp = "testing ";
char* myfifo = "/tmp/myfifo";
mkfifo(myfifo,0666);
printf("Run Reader process to read the FIFO File\n");
fd = open(myfifo,O_WRONLY);
//like this it will write untill EOF,CTRL  + C
 while(1){
  write(fd,tmp,sizeof(tmp));
 }
 //like this it will write till MAX_BUFF
 //for(i = 0;i < MAX_BUFF;i++){
//write(fd,tmp,sizeof(tmp));
 //}
 
close(fd);
unlink(myfifo);
return 0;
}
