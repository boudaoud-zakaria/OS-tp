#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    int arrayProcessSize;
    printf("enter tha size of process array :");
    scanf("%d" ,& arrayProcessSize);
    pid_t process[arrayProcessSize];
    printf("\n you  have %d Child and %d Parent !\n" , arrayProcessSize , arrayProcessSize);
    for (int i = 0; i < arrayProcessSize; i++)
    {
        /* code */
        process[i] = fork();
        if(process[i] < 0){
            perror("\nfork faild");
            exit(1);
        }
        if(process[i] == 0){
            printf("Child process number %d is urnning ... \n"  , i+1);
            sleep(arrayProcessSize - i);  //!wait just 2 sacends
            printf("i am child number %d and i was sleeped %d S \n" , i+1 , arrayProcessSize - i);
            exit(0);
        }
    }
    for (int i = 0; i < arrayProcessSize; i++) {
        wait(NULL);
    }

    printf("All child processes have finished.\n");
}