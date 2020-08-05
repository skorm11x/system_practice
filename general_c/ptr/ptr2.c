#include <stdlib.h>
#include <stdio.h>

void pass(char *, char *);


int main(int argc, char * argv[]){

    char * word1;
    char kitty [32] = "kitty kat attack time";
    char b = 'b';
    printf("word 1 address: %x, kitty address: %x\n", word1, &kitty);
    word1 = &kitty[0];
    printf("word 1 address: %x, kitty address: %x\n", word1, &kitty);
    printf("b address: %x\n", &b);
    word1 = &b;
    printf("word 1 address: %x, kitty address: %x\n", word1, &kitty);

    pass(&word1, &kitty);

    printf("post pass word address: %x, kitty address: %x\n", word1, &kitty);
    printf("word1 value: %c, b address: %x\n", *word1, &b);


    return 0;
}

/*
 * Explanation: This is a c programming "gotcha" moment of pass by value, pass by reference etc.
 * In this case we pass the address of word1 and kitty to the void function pass
 * Thus, the formal paramaters of the void function are pointers to those said addresses passed (actual paramaters)
 * 
 * SO: Remember that this formal paramaters pointer is ITSELF different in address than the address
 * passed to the function. In the case of stack it is a lower address of amount =
 * to the type of pointer (the size based on architecture, 32bit, 64 bit etc). 
 * 
 * doing hex math results in difference of 56, 7 bytes, including the first resolves those
 * 8 bytes difference hence 64 bit machine. 
 * 
 * NOTE: this resolves to the pointer on pass function being a **ptr, or pointer that
 * points to an address. 
 * 
 * Thus, we have reviewed pointers and their functionality in C relating to function calls.
 */ 
void pass (char * formalParam1, char * formalParam2){
    printf("the size of the formal paramaers char ptr: %d\n", sizeof(formalParam1));
    printf("function is modifying formal params/ word1 %x, kitty %x\n", &formalParam1, &formalParam2);
    *formalParam1 = formalParam2; //word1 ptr now points to kitty again
    printf("formal params1, params2: %x, %x\n", formalParam1, formalParam2);
}