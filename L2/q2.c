/*
=====================================================
    q2.c (Lab 2)
    Jonah Siegle (3020950)
=====================================================

Explaination:
_________________
The file descriptor appears to be read by both the child and parent process.
Both appear to be able to write text to the file concurrently.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int file = open("sample.txt", O_WRONLY | O_APPEND);

    if (file < 0) {
        printf("Cannot open file. \n");
        return 1;
    }

    int fVal = fork();

    if (fVal == 0) { //child procees
        char * string = "this is some text from the child";
        write(file, string, strlen(string));
    } else if (fVal > 0) { //parent process
        char * string = "this is some text from the parent";
        write(file, string, strlen(string));
    } else { //error
        printf("Fork error.\n");
    } 

    close(file);

    return 0;
}
