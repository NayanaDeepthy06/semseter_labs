#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* thread_function(void* arg){
    printf("IAM the child thread\n");
    sleep(2);
    printf("child thread is terminated!!!\n");
    return NULL;
}

int main(){
    pthread_t t;
    printf("Iam the parent thread\n");
    pthread_create(&t, NULL, thread_function, NULL);
    pthread_join(t, NULL);
    printf("Iam back to the parent thread:\n");
    return 0;
}
