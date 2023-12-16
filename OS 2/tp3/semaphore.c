#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore ;

void* thread1Fun(void* arg){
    sem_wait(&semaphore);
    int value =*(int*)arg;
    printf("thread number one with value of arg : %d \n", value);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void* thread2Fun(void* arg){
    sem_wait(&semaphore);
    int value =*(int*)arg;
    printf("thread number tow with value of arg : %d\n", value);
    sem_post(&semaphore);
    pthread_exit(NULL);
}

void main(int argc , char* argv[]){
    sem_init(&semaphore , 0 , 1);
    pthread_t thread1 , thread2;
    int id1 = 1;
    int id2 = 2;
    if(pthread_create(&thread1 , NULL , thread1Fun , &id1) != 0){
        perror("pthread_creat");
        exit(1);
    }
    if(pthread_create(&thread2 , NULL , thread2Fun , &id2) != 0){
        perror("pthread_creat");
        exit(1);
    }
    pthread_join(thread1 , NULL);
    pthread_join(thread2 , NULL);
    sem_destroy(&semaphore);
}
