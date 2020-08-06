#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h> 
#include <ctype.h>
#include "ptr3.h"

/*
 * Playing with threads in a more advanced setting. Exploring thread stack and heap.  
 * Use cases in process spawn (fork, exec family) and threading without IPC rn
 * 
 */


/* this function is run by the second thread */
void *inc_x(void *x_void_ptr) {

    /* increment x to 100 */
    int *x_ptr = (int *)x_void_ptr;
    while(++(*x_ptr) < 100);

    printf("x increment finished\n");

    /* the function must return something - NULL will do */
    return NULL;

}



//TODO: adapt for real world file processing problem
int main(int argc, char **argv){

    /*
        Note: C language does not official support **what version?**
        so this details POSIX threads. gcc compiler.
        --Update, C11 standards include concepts of threads. glibc is considered
        thread safe with compiler flags even on C99

        Remember, Threads share heap memory space and are designed to be small
        units of processing inside of an exisiting process. 
        They DO NOT share the same stack
        They DO share code section, data section, and operating system resources
        (obviously heap) but also open file handles && signals.

     */

    pthread_t * threadList; //a pointer to our dynamically allocated threadlist 

    threadList = malloc(sizeof(pthread_t) *1); //initially allocate only 1 slot

    printf("The size of the pthread_t variable, for reference, %ld bytes\n", sizeof(threadList[0]));

    //MVP multithreading from the grounds up then experimenting
    //http://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/

    int x = 0, y = 0;

    /* show the initial values of x and y */
    printf("x: %d, y: %d\n", x, y);

    /* create the secondary thread to do some incrementation */
    if(pthread_create(&threadList[0], NULL, inc_x, &x)){
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while(++y < 100);

    printf("y increment finished\n");

    /* wait for the second thread to finish */
    if(pthread_join(threadList[0], NULL)) {

    fprintf(stderr, "Error joining thread\n");
    return 2;

    }

    /* show the results - x is now 100 thanks to the second thread */
    printf("x: %d, y: %d\n", x, y);


    free(threadList);

    return 0;
}