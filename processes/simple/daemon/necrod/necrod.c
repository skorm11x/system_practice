#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*  This is an extension of the simple/zombie_spawn program
 *  designed to spawn zombie children and clutter up the pid
 *  table.
 * 
 *  This program will change the parent process into a daemon
 *  that will launch (at some point?) during boot 
 *  (assumed - want to observe) and fill up the pid table 
 *  preventing any other processes from being launch like xorg?
 *  gui? bash? Results noted below and tested in VM:
 * 
 *  
 *  
 *  @author: Christopher J. Kosik
 *  @date: 23 July 2020
 */ 

int main( int argc, char * argv[]){

    /*
        Daemon process reviewed:
        fork() -> umask(0) -> start new session, close
        STDIN, STDOUT, STDERR
    */

    pid_t necro_id = 0;
    pid_t sid = 0;

    necro_id = fork();

    if (necro_id < 0){
        exit(1); //fork failure
    }
    if (necro_id > 0){
        exit(0); //fork success, kill current process
    }
    //change child into daemon process, necrod

    umask(0); //Change the file mode mask according to the needs of the daemon
    sid = setsid();

    if(sid < 0){
        exit(1);// starting new session failed
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //begin necro-ing
   while(1){
       pid_t zomb;
       zomb = fork();
       if(zomb == 0){
           //success in child creation, execute new code to
           //have child exit with parent NOT waiting

            //Remember: argv and env of execve are terminated by null ptrs
            char *newargv[] = { NULL, " ", " ", NULL };
            char *newenviron[] = { NULL };
            execve(".child", newargv, newenviron);
       }

   }

    return 0;
}