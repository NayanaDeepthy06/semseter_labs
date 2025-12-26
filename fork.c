#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
// int main(){
//     pid_t pid;
//     pid = fork();
//     if(pid<0){
//         printf("fork failed\n");
//     }
//     else if(pid ==0){
//         printf(" child process is created sucessfully !!! with id: ");
//         printf("%d\n",getpid());
//     }
//     else{
//         printf("the parent proces is created sucessfully with id :%d",getppid());
//     }
// iimplement fork sysrem call 

int main() {
    pid_t pid;

    pid = fork();   // create child process

    if (pid < 0) {
        // fork failed
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // child process
        printf("Hello from Child Process\n");
        printf("Child PID: %d\n", getpid());
    }
    else {
        // parent process
        printf("Hello from Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
