#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 

int main(int argc, char * argv[]){
    int c;


    printf("I'm afraid I can't do that dave.. \n");
    printf("But this is my process id and my parent: %d , %d \n", getpid(), getppid());
    printf("for reference.. goodbye..\n");

    printf("Enter a char :\n");
    c = getchar();
    printf("you enetered: %c\n", c);

    return 0;
}