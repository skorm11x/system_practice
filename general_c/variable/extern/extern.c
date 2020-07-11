/**
 * This C program goes over the extern keyword in C.
 * 
 * @author: Christopher J. Kosik
 * @date: 11-7-2020
 */


#include <stdio.h>
#include "extern.h"

extern int var;

/*
    What happens if we declare and initialize a variable
    without defining it first? is memory allocated?

    Remember: we can declare any # of times but only 
    define once.
*/
extern int var2 = 0;
int main(void){

    var = 10;
    var2 = 5;
    printf("var value from header: %d\n", var);
    printf("var2 value from extern assignment: %d\n",var2);

    /*
        Yes, per C standard this method works for getting
        the compiler to allocate memory for the variable.
    */

    return 0;

}