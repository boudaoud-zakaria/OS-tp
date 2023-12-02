#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int var_globale = 0;

void* A(void* arg){
    int thread_arg = *(int*)arg;
    int arg_return = 50;
    for (double i = 0; i < 1000; i++)
    {
        var_globale++;
    }
    return (void*)(intptr_t)arg_return;
}

void* B(void* arg){
    int thread_arg = *(int*)arg;
    int arg_value = *(int*)arg;
    int arg_return = 50;
    for (double i = 0; i < 1000; i++)
    {
        var_globale--;
    }
    return (void*)(intptr_t)arg_return;
}

void main(){
    pthread_t th_1 , th_2;
    int arg1 = 20, arg2 = 30;
    void* resultA;
    void* resultB;
    if(pthread_create(&th_1 , NULL , &A ,&arg1) != 0){
        perror("pthread_create");
        exit(1);
    }
    if(pthread_create(&th_2 , NULL , &B ,&arg2) != 0){
        perror("pthread_create");
        exit(1);
    }
    if(pthread_join(th_1 , NULL) != 0){
        perror("pthread_join");
        exit(1);
    }
    if(pthread_join(th_2 , NULL) != 0){
        perror("pthread_join");
        exit(1);
    }
    printf("the value of var globale is %d \n" , var_globale);
    int arg_return_A = (int)(intptr_t)resultA;
    int arg_return_B = (int)(intptr_t)resultB;
    printf("value of function A return is %d \n" , arg_return_A);
    printf("value of function B return is %d \n" , arg_return_B);
}