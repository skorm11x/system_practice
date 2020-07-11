/**
 * This example demonstrates the register keyword in C
 * 
 * @author: Christopher J. Kosik
 * @date: 11-7-2020
 */ 


#include <stdio.h>

/*
 The keyword register hints to compiler that a given
 variable can be put in a register. It’s compiler’s 
 choice to put it in a register or not. Generally, 
 compilers themselves do optimizations and put the 
 variables in register. 
*/

int main(void){

    
    //int* a = &i; 
    //you cannot get address of a register..
    //makes sense as it is not memory and has no address

    int i = 10; 
    register int* a = &i; 
    printf("%d", *a); 
    getchar(); 
    return 0; 
 
    
}