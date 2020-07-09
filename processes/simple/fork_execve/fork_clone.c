#include <stdio.h>  //location of pid_t
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>  
#include <string.h>
#include <sys/wait.h>
#include <errno.h> 

int main(int argc, char* argv[]){
    pid_t parent,child;

    printf("hello world.. testing processes forking and creation");
    parent = getpid(); //get current pid
    printf("Current PID: %d\n", parent);

    child = fork();
        if(child < 0){
            //FAILURE
            printf("Error forking process: %s\n", strerror( errno ));
        }
        else if(child != 0){
            wait(NULL); //wait for child process to join*
        }
        else if(child == 0){
            //SUCCESS
            printf("New child PID: %d with parent PID: %d\n", getpid(), getppid());

            /*
                Taken from example shown in man
            */
            char *newargv[] = { NULL, "hello", "world", NULL };
            char *newenviron[] = { NULL };
            newargv[0] = "dave"; //hard code the name of the binary for test
            execve("dave",newargv, newenviron);
            perror("execve");   /* execve() returns only on error */
            exit(EXIT_FAILURE);
        }



    return 0;
}