#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    printf("Thread ID: %lu running\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    if (pthread_equal(t1, t2))
        printf("Threads are equal\n");
    else
        printf("Threads are NOT equal\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads completed.\n");
    return 0;
}
