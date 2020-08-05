#include <stdlib.h>
#include <stdio.h>


int main(int argc, char * argv[]){

    char a = 'a';
    char * ptr;
    ptr = &a; //ptr now pts to a

    char * hello =  "hello";

    //%x ==  hexadecimal
    printf("this is a: %c and its address on the stack: %x\n", a, &a);
    printf("and this is ptr: %c and its address: %x\n",*ptr, ptr);
    //increment a address on stack?
    ptr++;
    printf("incremented ptr value on stack: %x and its value: %c\n",(ptr), *ptr);
    printf("hello: %s %x\n", hello, &hello);
    hello = "uh oh we are going too long now.. how will stack respond?";
    printf("hello: %s where the previous hello is lost as address contents overwrite %x\n", hello, &hello);

    return 0;
}