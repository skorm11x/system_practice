#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "aparser.h"

/*/
    Using C 11 _Generic allows pseudo polymorphism in C w/o objects

*/
#define is_const_int(x) _Generic((&x),  \
        const int *: "a const int",     \
        int *:       "a non-const int", \
        default:     "of other type")

// C11 Generic macro for returning data type of variable
#define get_data_type(x) _Generic((&x), \                 
        unsigned char *:   "uchar ptr", \   
        signed char *:   "signed char ptr", \
        char *:   "char ptr", \
        int *:    "int ptr",  \
        unsigned int *: "uint ptr", \
        short *: "short ptr", \
        unsigned short *: "ushort ptr", \
        long *: "long ptr", \
        unsigned long *: "ulong ptr", \
        char: "char", \
        signed char: "signed char", \
        unsigned char: "unsigned char", \
        short int: "short int", \
        unsigned short int: "unsigned short int", \
        int: "int", \
        unsigned int: "unsigned int", \
        long int: "long int", \
        unsigned long int: "unsigned long int", \
        long long int: "long long int", \
        unsigned long long int: "unsigned long long int", \
        float: "float", \
        double: "double", \
        long double: "long double", \
        default: "unknown type.")


int main(int argc, char * argv[]){


    

    return 0;
}