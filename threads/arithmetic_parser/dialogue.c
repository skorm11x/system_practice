#include <stdio.h>
#include "aparser.h"

/*
    Say Hello. 
*/
void hello(){
    printf("hello\n");
}

/*
    Say bye.
*/
void bye(){
    printf("bye\n");
}

/*
    Ask user for arithmetic expression
    @return chr array with expression the user entered.
    
*/
char * ask_for_expression(int isValid){
    char *entered_expression;
    char a = 'a';
    entered_expression = &a;

    return entered_expression;
}

/*
    Inform user of process file operating mode
    @return chr array with file operating mode
*/
char * inform_user_file_mode(char *filename ){
    char *file_mode;
    char a = 'a';
    file_mode = &a;

    return file_mode;
}



