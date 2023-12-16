#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define n 5

void main(int argc , char* argv[]){
    pid_t process;
    for (int i = 0; i < n; i++)
    {
        process = fork();
        if(process < 0 ){
            perror("process Not Found \n");
            exit(1);
        }
        else if(process == 0){
            if(getpid() % 2 == 0){
                printf("paire fils with PID : %d \n" , getpid());
            }
            else{
                printf("impaire fils with PID : %d \n" , getpid());
            }
            exit(1);
        }
    }
    for (int i = 0; i < n; i++) wait(NULL);
    printf("All parent has finiched with PID = %d \n" , getpid());
}