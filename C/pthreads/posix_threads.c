#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 6

// The signature of a coroutine is void* (*)(void*)
void *coroutine(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    printf("Hello from thread %ld!\n", tid);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; ++t) {
        printf("Creating thread: %ld\n", (long) t);
        rc = pthread_create(&threads[t], NULL, coroutine, (void *) t);
        if (rc) {
            printf("ERROR: pthread_create(): %d\n", rc);
            return -1;
        }
    }

    pthread_exit(NULL);
}
