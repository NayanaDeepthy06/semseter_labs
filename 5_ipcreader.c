#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
    int shmid;
    char *s;
    shmid = shmget(1234,50,IPC_CREAT|0666);
    s = shmat(shmid,NULL,0);
    printf("message read from writre is %s",s);
    shmdt(s);
    return 0;
}