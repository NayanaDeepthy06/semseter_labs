#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid = fork();
    if(pid<0){
        printf("fork failed\n");
        exit(1);
    }
    else if(pid ==0){
        printf("child process is created succesfully!!");
        printf("child PID:%d\n",getpid());
        printf("child parents id id :%d\n",getppid());
        printf("child process exiting:...\n");
        exit(0);
    }
    else{
        printf("parent process created !!!");
        printf("parent process id  :%d\n",getpid());
        printf("waiting for child process to terminate ...\n");
        wait(NULL);
        printf("child finished execution  \n");
        printf("parent process exiting ...\n");
        exit(0);

    }
}
