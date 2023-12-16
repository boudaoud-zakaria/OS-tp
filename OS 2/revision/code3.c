#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc , char* argv[]){
    pid_t process;
    if(argc > 1){
        for (int i = 1; i < argc; i++)
        {
            process = fork();
            if(process < 0 ){
                perror("process Not Found \n");
                exit(1);
            }
            else if(process == 0){
                printf("Child process number %d is urnning with data : %s \n", i , argv[i]);
                exit(1);
            }
        }
        for (int i = 0; i < argc; i++) wait(NULL);
        printf("All child processes have finished.\n parent PID : %d \n" , getpid());
    }
}