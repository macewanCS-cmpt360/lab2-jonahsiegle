/*
=====================================================
    q3.c (Lab 2)
    Jonah Siegle (3020950)
=====================================================

Explaination:
_________________

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) 
{
    int fVal = fork();

    if (fVal == 0) { //child process
        printf("hello \n");
    } else if (fVal > 0) { //parent process
        sleep(1);
        printf("goodbye \n");
    } else { //fork error
        printf("Fork error.\n");
    }

    return 0;
}
