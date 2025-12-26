#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd;
    char buffer[100];
    // open a file 
    fd = open("sample.txt",O_CREAT|O_RDWR,0644);
    if(fd<0){
        printf("file opening failed\n");
        return 1;
    }
    write(fd,"hello Operating Systems \n",26);
    lseek(fd,0,SEEK_SET);// setting pointer to the beginning of the file 
    read(fd,buffer,26);/// reading the file 
    buffer[23]='\0';
    printf("data read from the file is %s",buffer);
    close(fd);
    return 0;


}