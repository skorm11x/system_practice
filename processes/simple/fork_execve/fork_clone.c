#include <stdio.h>  
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>  
#include <string.h>
#include <sys/wait.h>
#include <errno.h> 

/**
 * This is a very simple program testing out
 * system calls like fork, exec, & wait.
 * I "learned" these things in system programming
 * but it was very poorly addressed.
 *  
 * @author: Christopher J. Kosik
 * @date: 15-7-2020
 */ 

int main(int argc, char* argv[]){
    pid_t parent,child,watch;
    int c, status;

    printf("hello world.. testing processes forking and creation");
    parent = getpid(); //get current pid
    printf("Current PID: %d\n", parent);

    child = fork();
        if(child < 0){
            printf("In parent process, child could not be created\n");
            printf("Error forking process: %s\n", strerror( errno ));
        }
        else if(child > 0){
            //we are in the parent process
            printf("child >0 in parent process.\n");
        }
        else if(child == 0){
            //SUCCESS, a child is created and we are in its process
            printf("New child PID: %d with parent PID: %d\n", getpid(), getppid());

            /*
                Taken from example shown in man
            */
            char *newargv[] = { NULL, "hello", "world", NULL };
            char *newenviron[] = { NULL };
            newargv[0] = "dave"; //hard code the name of the binary for test
            printf("Parent sending child new dave compiled code.\n");
            if(execve("dave",newargv, newenviron) == -1){
                //Remember, execve only returns in error
                perror("Could not execve");
                return 1;
            }


            
        }

        /*
            We MUST call wait() outside of check if child == 0.
            Why? because else the parent process dies before the child
            process and we have an orphan process that is adopted by 
            the father/mother process PID 1 == Init. Init will eventually
            perform the wait() call so those processes can die.

            We have another pid type watching, through the 
            sys call wait, any child process of the parent
            process. This acts as blocking code and is released
            when the parent detects the child process is done

            The id of the returning processes is returned and stored
            in watch of type pid_t
        */
        watch  = wait(&status);
        printf("dave process: %d is detected as finished by parent.\n",watch);



    return 0;
}