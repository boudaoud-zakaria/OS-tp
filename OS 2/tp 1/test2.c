#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//!facotrial function :
int factorial(int n){
    if(n == 1) 
    return 1;
    else{
        return n * factorial(n-1);
    }
}

//!sun function 
int sum(int n){
    if(n == 0)
    return 0;
    else{
        return n + sum(n-1);
    }
}

void main(int argc, char const *argv[])
{
    int number = 5;
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else{
        if(pid == 0){
            printf("Child process (PID %d) is running , and factorlial of %d is %d.\n", getpid() , number , factorial(number));
            pid_t parent = getppid();
            printf("the parent of this child is : %d \n" , parent);
        }
        else{
            printf("Parent process (PID %d) is running , and sun of 0 + ... + %d is %d.\n", getpid() , number , sum(number));
        }
    }
}
