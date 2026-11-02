#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NR_LOOP 10000
static void t1_function(void* arg);
static void t2_function(void* arg);

static int counter = 0;

sem_t sem1;

int main(void) {
    pthread_t t1, t2;
    sem_init(&sem1, 0, 1);
    pthread_create(&t1, NULL, *t1_function, NULL);
    pthread_create(&t2, NULL, *t2_function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Valor counter final: %d\n", counter);

    return 0;
}

static void t1_function(void* arg) {
    for (int i = 0; i < NR_LOOP ; i++) {
        sem_wait(&sem1);
        counter += 1;
        sem_post(&sem1);
    }
}

static void t2_function(void* arg) {
    for (int i = 0; i < NR_LOOP ; i++) {
        sem_wait(&sem1);
        counter -= 1;
        sem_post(&sem1);
    }
}