#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a = 1;

void* A(void* arg){
    int thread_arg = *(int *)arg;
    printf("function A and value of my arg is :%d \n" , thread_arg);
    for (int i = 0; i < 100; i++)
    {
        a++;
    }
}

void* B(void* arg){
    printf("functino B \n");
    for (int i = 0; i < 100; i++)
    {
        a--;
    }
}

void main(){
    pthread_t p1 , p2;
    int my_arg = 24;
    if(pthread_create(&p1 , NULL , &A , &my_arg) != 0){
        perror("ptread_create");
        exit(1);
    }
    if(pthread_create(&p2 , NULL , &B , NULL) != 0){
        perror("pthread_join");
        exit(1);
    }
    if(pthread_join(p1 , NULL)){
        perror("ptrhead_join");
        exit(1);
    }
    if(pthread_join(p2 , NULL)){
        perror("ptrhead_join");
        exit(1);
    }
    printf(" the value of A is : %d\n" , a);
}