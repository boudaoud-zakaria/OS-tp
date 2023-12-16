#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    char text[30];
    int nombre;
} thread_args;

void *afficher_text(void *arg1) {
    thread_args thread_arg = *(thread_args *)arg1;
    for (int i = 0; i < thread_arg.nombre; i++)
    {
        /* code */
        printf("%s" , thread_arg.text);
    }
}

void main(){
    pthread_t p1 , p2 , p3;
    thread_args arg1 , arg2 , arg3;
    arg1.text == "Bonjour";
    arg1.nombre = 10;
    pthread_create(&p1 , NULL , afficher_text , &arg1);
    pthread_join(p1 , NULL);
    arg2.text == "Bonsoire";
    arg2.nombre = 15;
    pthread_create(&p1 , NULL , afficher_text , &arg2);
    pthread_join(p1 , NULL);
    arg3.text == "\n";
    arg3.nombre = 5;
    pthread_create(&p1 , NULL , afficher_text , &arg3 );
    pthread_join(p1 , NULL);
}
