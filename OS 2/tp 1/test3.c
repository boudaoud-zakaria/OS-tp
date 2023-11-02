#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t process = fork();
    if(process < 0){
        perror("fork faild");
        exit(1);
    }
    if(process == 0){
        printf("Child process is urnning ... \n");
        sleep(2);  //!wait just 2 sacends
        printf("sleeped 2S \n");
    }
    else{
        printf("Parent process in waiting for the child to finish ...\n");
        wait(NULL); //!wait the child process to finish 
        printf("Child porcess has finished...\n ");
    }
}