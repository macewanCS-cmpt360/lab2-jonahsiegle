/*
=====================================================
    q3.c (Lab 2)
    Jonah Siegle (3020950)
=====================================================

Explaination:
_________________
When you close stdout and call printf() no text will be printed
into the shell. 
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int fVal = fork();

    if (fVal == 0) { //child process
        close(STDOUT_FILENO);
        printf("I am a child process.\n");
    }  else if (fVal > 0) {
        printf("Hello I am parent.\n");
    }

    return 0;
}