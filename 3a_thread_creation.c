#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("I am a child thread.\n");
    printf("My Process ID is: %d\n", getpid());
    return NULL;
}

int main() {
    pthread_t t;

    printf("I am main thread.\n");
    printf("My Process ID is: %d\n", getpid());

    pthread_create(&t, NULL, thread_function, NULL);

    pthread_exit(NULL);   // keeps main alive till thread finishes
    return 0;
}
