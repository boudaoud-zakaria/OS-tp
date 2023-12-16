#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){


    pid_t process[5];
    for (int i = 0; i < 3; i++)
    {
        /* code */
        process[i] = fork();
        if(process[i] < 0){
            perror("\nfork faild");
            exit(1);
        }
        if(process[i] == 0){
            printf("Child process number %d is urnning ... \n"  , i+1);
            // sleep(arrayProcessSize - i);  //!wait just 2 sacend
            exit(0);
        }
        else{
            printf("Parent process number %d in waiting for the child to finish ...\n" , i+1);
            wait(NULL); //!wait the child process to finish 
            printf("Child porcess number %d has finished...\n " , i+1);
        }
    }
    
    return 0;
}