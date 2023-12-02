#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* A(void* arg){
    printf("function A \n");
}

void* B(void* arg){
    printf("function B \n");
}

void main(){
    pthread_t th_1 , th_2;
    pthread_create(&th_1 , NULL , &A ,NULL);
    pthread_create(&th_2 , NULL , &B ,NULL);
    pthread_join(th_1 , NULL);
    pthread_join(th_2 , NULL);
}