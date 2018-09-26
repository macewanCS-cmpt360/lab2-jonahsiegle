/*
=====================================================
    q1.c (Lab 2)
    Jonah Siegle (3020950)
=====================================================

Explaination:
_________________
When this program runs it sets an initial value to the variable x
of 5. After fork is called the parent and child process set x to unique
values to observe the difference. For both processes the value for x
always starts at it's original (being 5 in this case). Each process will then
set their own unique values to the variable. When the program is ran the
value of x always starts at 5 for each process regardless of the value being set
by the parent. This demonstrates how fork() will create an entirely new
instance/process of the program independent of each other.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int x = 0;

int main(void)
{
    x = 5;
    int fVal = fork();

    printf("the x val after fork is: %d\n", x);

    if (fVal == 0) { //child procress
        printf("the x vale in child process: %d\n", x);
        x = 10;
        printf("the x value in child process after chaning: %d\n", x);
    } else if (fVal > 0) { //parent process
        printf("the x vale in parent process: %d\n", x);
        x = 15;
        printf("the x value in parent process after chaning: %d\n", x);        
    } else { //error
        printf("Something went wrong.\n");
    }

    return 0;
}
