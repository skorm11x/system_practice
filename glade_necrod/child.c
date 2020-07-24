#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>  
#include <string.h>
#include <sys/wait.h>
#include <errno.h> 

// #ifndef CLI_OUT
// #define CLI_OUT
// #endif

/**
 * Child counterpart of parent.c
 * This program opens up says "i am zombie", and then exits
 * 
 * @author: Christopher J. Kosik
 * @date: 15-7-2020
 */ 

int main (void){
    #ifdef CLI_OUT
        printf("I am a zombie.. with pid: %d\n", getpid());
    #endif
    exit(EXIT_SUCCESS);
}