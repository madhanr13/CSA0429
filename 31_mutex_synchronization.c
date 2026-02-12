#include <stdio.h>
#include <pthread.h>

#define N 1000000

int counter = 0;               // Shared resource
pthread_mutex_t lock;          // Mutex

void* increment(void* arg) {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&lock);   // Enter critical section
        counter++;
        pthread_mutex_unlock(&lock); // Exit critical section
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    printf("Final Counter Value: %d\n", counter);

    return 0;
}
    