#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc , char *argv[]){
    //! argv[0] = ./run 
    //! argv[1] = command , like 'ps'
    //! argv[2] = setting , like '-aux'
    //! argc = the length of argv array 

    if(argc < 2){
        printf("Try again, use any order... \n");
        exit(1);
    }
    
    if(execvp(argv[1] , &argv[1]) == -1){
        perror("execvp");
        exit(1);
    }
}
