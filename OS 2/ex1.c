#include<stdio.h>
#include <stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
// !++++++++++++++++++++++++++
int main ()
{
	pid_t child_pid = fork();
	int status;
	//? *****************
	if(child_pid == 0)
	{
		printf("fils (%d) appel ls..!\n",getpid());
		/* execlp("ls","ls","-afl",NULL); == system("ls -afl"); */
		//! Q1
		char *const arguments[] = {"ls", "-afl", NULL};
		//! ----------
    	if (execvp("lsl", arguments) == -1) {
        	perror("execvp");
			exit(1);
    	}
	}
	//? *****************
	else{
		printf("parent...!(%d)\n",getpid());
		//! Q2
		wait(&status);
		//! ----------
		if(WIFEXITED(status)){
        	printf("Child process (PID: %d) exited with status %d.\n", child_pid, WEXITSTATUS(status));
        }
		//! ----------
        	else{
            	printf("child process did not exit normaly \n");
        	}
	}
	//? *****************
	return 0;
}