#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10
#define THREADS 5

double B[N][N], C[N][N], A[N][N];
pthread_t threads[THREADS];

typedef struct {
    int start;
    int end;
} thread_args;

void *producer(void *arg) {
    thread_args *args = (thread_args *)arg;
    int i, j, k;
    for (i = args->start; i < args->end; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 0;
            for (k = 0; k < N; k++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }
    return NULL;
}

int main() {
    int i, j;
    thread_args args[THREADS];

    // Initialisation des matrices B et C
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            B[i][j] = 1;
            C[i][j] = 1;
        }
    } 
    //! matrice B
    printf("matrix B \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", B[i][j]);
        }
        printf("\n");
    }
    //! matrice C
    printf("matrix C \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    // Création des threads
    for (i = 0; i < THREADS; i++) {
        args[i].start = i * (N / THREADS);
        args[i].end = (i + 1) * (N / THREADS);
        pthread_create(&threads[i], NULL, producer, &args[i]);
    }

    // Attente de la fin des threads
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Affichage de la matrice A
    printf("Matrice A :\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
