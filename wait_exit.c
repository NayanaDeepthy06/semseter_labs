#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>// <sys/types.h>
int main(){
    int status;
    pid_t pid;
    pid = fork();
    if(pid<0){
        printf("fork failed\n");
    }
    else if(pid ==0){
        printf("child process is created sucessfully !!!\n");
        printf("\n child process id is :%d",getpid());
        exit(5);
    }
    else{
        wait(&status);
        printf("\nparent process is created !!");
        printf("\n parent process id is :%d",getpid());
        printf("\n child process exited with:%d",WEXITSTATUS(status));

        
    }
    return 0;
}

