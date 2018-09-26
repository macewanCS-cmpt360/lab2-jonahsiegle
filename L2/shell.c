/*
=====================================================
    shell.c (Lab 2)
    Jonah Siegle (3020950)
=====================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    while (1) {
        char *cmdline;
        char *token = NULL;
        int i;
        char *args[10];

        int background = 0;

	    cmdline = calloc(1, 1024);
	    i = 0;

        printf("prompt> ");
        fgets(cmdline, 1024, stdin);

        token = strtok(cmdline, "\n ");
	    while (token != NULL) {
		    args[i++] = strdup(token);
		    token = strtok(NULL, "\n ");
	    }
	    args[i] = NULL;

        if (strcmp(args[i-1], "&") == 0) { //handle running in the background
            args[i-1] = NULL;
            background = 1;
        } 

        int fVale = fork();

        if (fVale == 0) {
            execvp(args[0], args);
        } else if (fVale > 0) {
            if (background == 0) {
                 wait(NULL);
            }
        } else {
	        fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);
            exit(1);
        }

        free(cmdline);
    }
}
