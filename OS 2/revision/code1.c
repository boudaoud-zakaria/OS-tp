#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc , char* argv[]){
    pid_t process;
    for (int i = 0; i < 3; i++)
    {
        process = fork();
        if(process < 0 ){
            perror("process Not Found \n");
            exit(1);
        }
        else if(process == 0){
            printf("child number %d and prosesse with PID = %d \n", i+1 ,getpid());
            exit(1);
        }
    }
    wait(NULL);
    printf("parent wth PID = %d \n" , getpid());
}