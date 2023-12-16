#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t S1, S2;
int nl = 0;

void *reader(void *arg) {
    int data = *(int*)arg;
    sem_wait(&S1);
    nl++;
    if (nl == 1) {
        sem_wait(&S2);
    }
    sem_post(&S1);
    //! critical section
    printf("read the data : %d\n", data );
    //! the end of the critical section
    sem_wait(&S1);
    nl--;
    if (nl == 0) {
        sem_post(&S2);
    }
    sem_post(&S1);
    //! data return :
    pthread_exit((void *)data);
}

void *writer(void *arg) {
    int data = *(int*)arg;
    sem_wait(&S2);
    //! critical section
    printf("Write the data : %d\n", data);
    //! the end of the critical section
    sem_post(&S2);
}

void main() {
    int data = 7;
    pthread_t read, write;
    sem_init(&S1, 0, 1);
    sem_init(&S2, 0, 1);
    if(pthread_create(&read, NULL, reader, &data) != 0){
        perror("pthread_create");
        exit(1);
    }
    void *data_ptr;
    if(pthread_join(read, &data_ptr) != 0){
        perror("pthread_join");
        exit(1);
    }

    int data_reader = (int)data_ptr;

    if(pthread_create(&write, NULL, writer, &data_reader) != 0){
        perror("pthread_create");
        exit(1);
    }
    if(pthread_join(write, NULL) != 0){
        perror("pthread_join");
        exit(1);
    }
    sem_destroy(&S1);
    sem_destroy(&S2);
}