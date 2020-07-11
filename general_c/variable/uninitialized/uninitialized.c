#include <stdio.h>

/*
 Example illustrating basic variable initialization

 static variables (file scope and function static)
 are initialized to zero.

 Non-static variables (local variables) are indeterminate.
 Reading them prior to assigning a value results in 
 undefined behavior.

 @author: Christopher J. Kosik
 @date: 11-7-2020
 */

int var1; //zero

int main(void){
    //static variable section
    int var2; //zero
    static int var3; //zero
    printf("var1, (non static) var2, var3 value: %d, %d, %d\n", var1,var2,var3);

    /*
        Why does compiler allow undeterministic behavior
        with undefined variables in C?

        check this out: http://catb.org/jargon/html/N/nasal-demons.html

    */

   return 0;

}