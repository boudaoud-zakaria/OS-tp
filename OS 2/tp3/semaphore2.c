#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Définition des sémaphores
sem_t sem_I1, sem_I2;

// Variable partagée pour l'alternance
int turn = 1; // 1 pour I1, 2 pour I2

// Fonction du processus P1
void *process_P1(void *arg) {
    for (int i = 0; i < 5; ++i) {
        printf("I1 ");
        sem_post(&sem_I2);
    }

    pthread_exit(NULL);
}

// Fonction du processus P2
void *process_P2(void *arg) {
    for (int i = 0; i < 5; ++i) {
        sem_wait(&sem_I2);

        // Exécution de I2
        printf("I2 ");

        // Exécution de I2 une deuxième fois
        printf("I2 ");

        // Changer le tour pour permettre à P1 de s'exécuter
        turn = 1;

        // Signal le sémaphore pour P1
        sem_post(&sem_I1);
    }

    pthread_exit(NULL);
}

int main() {
    // Initialisation des sémaphores
    sem_init(&sem_I1, 0, 0);
    sem_init(&sem_I2, 0, 0);

    // Création des threads pour les processus P1 et P2
    pthread_t thread_P1, thread_P2;

    pthread_create(&thread_P1, NULL, process_P1, NULL);
    pthread_create(&thread_P2, NULL, process_P2, NULL);

    // Initialisation du tour pour permettre à P1 de commencer
    turn = 1;

    // Signal le sémaphore pour P1
    sem_post(&sem_I1);

    // Attente de la terminaison des threads
    pthread_join(thread_P1, NULL);
    pthread_join(thread_P2, NULL);

    // Destruction des sémaphores
    sem_destroy(&sem_I1);
    sem_destroy(&sem_I2);

    return 0;
}
