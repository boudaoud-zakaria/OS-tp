#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    //! array Fork a child process
    pid_t t[3]; 

    for (int i = 0; i < 3; i++)
    {
        /* code */
        t[i] = fork();
        if (t[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (t[i] == 0) {
            //! This code is executed by the child process
            printf("Child process numbre %d (PID %d) is running.\n", i , getpid());
            exit(EXIT_SUCCESS); //? Exit the child process
        } 
        else {
            //! This code is executed by the parent process
            printf("Parent process numbre %d (PID %d) is running.\n", i , getpid());
        }
    }
}


