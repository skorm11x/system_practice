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
    //at this point init/ systemd pid == 1 takes over orphan process
    //we call umask(0) to modify new session permissions
    //we call setsid() to assign the process a new group

    
    /*
     *  Umask: sets the calling process creation mask to mask & 0777
     *  umask is used by open and mkdir system calls that create files  
     *  and modify permissions. 
     * 
     *  If parent directory has a default ACL umask is ignored.
     * 
     *  ACL: acl stands for access control lists. Every object can be
     *  thought of as having an associated ACL. ACL specifies the access
     *  permissions on associated object for individual user or group of users. 
     * 
     *  ACL broke defined by entry tags with specific types: ACL_USER, ACL_GROUP
     *  
     *  defined tags:
     *  ACL_USER_OBJ: denotes access rights for the file owner
     *  ACL_USER:     access rights for users identified by entry qualifier
     *  ACL_GROUP_OBJ: access rights for file group
     *  ACL_GROUP: group rights
     *  ACL_MASK:   maximum access rights that can be granted by entries type
     *              user, group obj, group
     *  ACL_OTHER: access for processes that do not match any other entry in acl
     * 
     * 
     *  
     */ 

    umask(0);


    /*
     * setsid(): run program in a new session. 
     * This can be a bit confusing and needs background information regarding
     * the several IDs associated with all processes
     * 
     * All processes have:
     * 
     * PID: processes ID, arbiotrary # identifying process. Unique while process
     * id has not been reclaimed via exit status.
     * 
     * PPID: parent process ID, process id of parent
     * 
     * PGID: process group ID, this is just the PID of the session leader. 
     * If PGID = PID then that process is the group leader
     * 
     * SID: This is the process ID of the session leader. 
     * 
     * Where sessions and process groups are just a way to treat a # of related processes
     * as a unit. members of the process group belong to the same session, but a session
     * may have multiple process groups.
     * 
     * Normally shell is a session leader. Every pipeline executed by shell will be a 
     * process group. 
     * 
     * What is a pipeline? : just a set up stream of pipes like i am used to doing
     * via the shell!. e.g.: ls -l | grep -i "hello" (list all files that match hello case insen)
     * 
     * Stated otherwise, we string together STDIN (0), STDOUT(1), STDERR(2) together 
     * for different programs.  
     * 
     */

    sid = setsid();


    if(sid < 0){
        // Return failure
        exit(1);
    }
    //at this point the process can be considered a daemon process. 

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