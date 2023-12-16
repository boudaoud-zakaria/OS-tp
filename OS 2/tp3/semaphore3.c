// #include<stdio.h>
// #include<stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>

// sem_t semaphore1 , semaphore2;
// int glValue = 0;

// void* function1(void* arg){
//     for (int i = 0; i < 10000; i++)
//     {
//         sem_wait(&semaphore1);
//         glValue++;
//         int value = 1;// *(int*)arg;
//         // printf("thread number one with arg value :%d \n" , value);
//         sem_post(&semaphore2);
//     }
    
//     pthread_exit(NULL);
// }
// void* function2(void* arg){
//     for (int i = 0; i < 10000; i++){
//         sem_wait(&semaphore2);
//         glValue--;
//         int value = 2;//*(int*)arg;
//         // printf("thread number tow with arg value :%d\n" , value);
//         sem_post(&semaphore1);
//     }
//     pthread_exit(NULL);
// }

// void main(int argc , char* argv[]){
//     sem_init(&semaphore1 , 0 , 1);
//     sem_init(&semaphore2 , 0 , 0);
//     pthread_t thread1 , thread2;
//     int id1 = 1;
//     int id2 = 2;

//     if(pthread_create(&thread1 , NULL , function1 , &id1) != 0){
//         perror("pthread_creat");
//         exit(1);
//     }
//     if(pthread_create(&thread2 , NULL , function2 , &id2) != 0){
//         perror("pthread_creat");
//         exit(1);
//     }
//     pthread_join(thread1 , NULL);
//     pthread_join(thread2 , NULL);
//     printf("\ngl value : %d\n" , glValue);
//     sem_destroy(&semaphore1);
//     sem_destroy(&semaphore2);
// }

#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore1 , semaphore2;

int nl = 0;

void* function1(void* arg){
    int value ;
    sem_wait(&semaphore2);
    nl++;
    if(nl == 1) 
    sem_wait(&semaphore1);
    sem_post(&semaphore2);
    printf("enter value of thread number one :");
    scanf("%d" ,&value);
    sem_wait(&semaphore2);
    nl--;
    if(nl == 0)
    sem_post(&semaphore1);
    sem_post(&semaphore2);
    pthread_exit(NULL);
}

void* function2(void* arg){
    sem_wait(&semaphore1);
    printf("thread number tow \n");
    sem_post(&semaphore1);
    pthread_exit(NULL);
}

void main(int argc , char* argv[]){
    sem_init(&semaphore1 , 0 , 1);
    sem_init(&semaphore2 , 0 , 1);
    pthread_t thread1 , thread2;

    if(pthread_create(&thread1 , NULL , function1 , NULL) != 0){
        perror("pthread_creat");
        exit(1);
    }
    if(pthread_create(&thread2 , NULL , function2 , NULL) != 0){
        perror("pthread_creat");
        exit(1);
    }
    pthread_join(thread1 , NULL);
    pthread_join(thread2 , NULL);
    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);
}

