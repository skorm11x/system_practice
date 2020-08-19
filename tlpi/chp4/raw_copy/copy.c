/************************************************\
 * My own
 * Typing it out by hand / self comment the cp program
 * from TLPI
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "tlpi_hdr.h"


#ifndef BUFF_SIZE
#define BUFF_SIZE 1024 //we need a buffer size to store chunks obv. 1kb should be enough static
#endif

int main(int argc, char *argv[]){
    //normally would use fopen etc.. now how to get flags and do raw etc.

    int inputFd, outputFd, openFlags; //we need a file descriptor per mode + flag values
    /*  what are file descriptors? oh right these are just to absorb the return status 
        when involing
        the raw system call so we can check the status! makes sense.
    */

   char buffer[BUFF_SIZE]; //a buffer for the chars..

   /*
        New stuff: these types are defined in <sys/types.h>
        Excellent resource on mode_t: https://jameshfisher.com/2017/02/24/what-is-mode_t/

        mode_t: composed of a bunch of bit packed booleans for description of file permissions
        difficult to read the bitmasks.. research into it later but basically value based on groups
        etc as expected

        size_t: this type just focuses around returning the size of an allocated block of memory/
        size of objects in memory
        now onto the new: 
        ssize_t: ... a signed version of size-t


   */
   mode_t filePerms;
   ssize_t numRead; 

   /*
        Because this program is simply emulating cp, we expect 3 arguments passed to it at runtime:
        0: program invocation, 1: first file (src), 2: second file (dest)
        e.g.: run this program and copy y into x
   */


  if((argc != 3) || strcmp(argv[1], "--help" == 0)){
      usageErr("did not pass 2 files or --help option. Exiting.");
  }


}
 