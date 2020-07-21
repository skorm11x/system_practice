#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*
 * A very simple program progressing from knowledge gained
 * of unix processes. We will creating a program that forks,
 * and starts a new process running in the root directory of
 * unix system as a daemon process. 
 * 
 * Note, we call setsid():
 * https://linux.die.net/man/2/setsid
 * to change the process group and deattach it to the shell
 * we run this program from as root (in order to keep it alive)
 * 
 */


/* 
 *  NOTE: the following example is started from and adapated
 *  from the following source: https://www.thegeekstuff.com/2012/02/c-daemon-process/
 */
int main(int argc, char* argv[]){

    FILE *fp= NULL;
    pid_t process_id = 0;
    pid_t sid = 0;

    // Create child process
    process_id = fork();
    // Indication of fork() failure
    if (process_id < 0){
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }
    // PARENT PROCESS. Need to kill it.
    if (process_id > 0){
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }
    //unmask the file mode
    umask(0);
    //set new session

    sid = setsid();


    if(sid < 0){
        // Return failure
        exit(1);
    }
    // Change the current working directory to root.
    chdir("/");
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Open a log file in write mode.
    fp = fopen ("Log.txt", "w+");

    while (1){
        //Dont block context switches, let the process sleep for some time
        sleep(1);
        fprintf(fp, "Logging info...\n");
        fflush(fp);
        // Implement and call some function that does core work for this daemon.
    }

    fclose(fp);
    return (0);

}