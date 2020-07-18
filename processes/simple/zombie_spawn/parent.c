#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>  
#include <string.h>
#include <sys/wait.h>
#include <errno.h> 

/**
 * This is a very simple program to test out the details
 * of zombie process. Goal of this program is to spawn
 * a very very large number of zombies.
 * E.g. how does OS handle zombies? How can i clean them?
 * At what point (lol) does the system break from process
 * table being full of zombie processes
 * 
 * This is the parent file that spawn child, calls exec for child binary
 * and DOES NOT wait() on child. All observations done through top w/filters
 * 
 * @author: Christopher J. Kosik
 * @date: 15-7-2020
 */

// #ifndef CLI_OUT
// #define CLI_OUT
// #endif

int main(void){
    pid_t parent, child1, child2, child3;

    #ifdef CLI_OUT
        printf("Starting zombie spawn application with pid: %d\n", getpid());
    #endif

    /*
        When the process that created the zombie ends,
        Init PID == 1 becomes the inheritor of the zombie processes. 
        Init periodically calls wait() to clean up zombies.
     */ 

    /*

        beware.. trying something dumb
        this will spawn infinite zombies blocking all
        other programs from launching due to pid tables.
        Observed correctly on my machine!
     */   

    while(1){
    child1 = fork();
        if(child1 <0){
            #ifdef CLI_OUT
                printf("In parent process, child could not be created\n");
                printf("Error forking process: %s\n", strerror( errno ));
            #endif    
        }
        else if(child1 > 0){
            //we are in the parent process
            #ifdef CLI_OUT
                printf("child >0 in parent process.\n");
            #endif
        }
        else{
            //child == 0
            //Remember: argv and env of execve are terminated by null ptrs
            char *newargv[] = { NULL, " ", " ", NULL };
            char *newenviron[] = { NULL };
            #ifdef CLI_OUT
                printf("New child PID: %d with parent PID: %d\n", getpid(), getppid());
            #endif    
            execve(".child", newargv, newenviron);
        }
    }


}