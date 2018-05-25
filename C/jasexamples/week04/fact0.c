// Function to compute factorials
// http://en.wikipedia.org/wiki/Factorial
// n! = 1*2*3*...*n
// Written by andrewt@cse, April 2013

#include <stdio.h>
#include <stdlib.h>

// factorial : int -> int
int factorial(int);

int main(void)
{
    int i = 1;
    while (i < 12) {
        printf("factorial(%d) = %d\n", 
               i, factorial(i));
        i = i + 1;
    }
    return 0;
}

int factorial(int n)
{
    int i;   // counter
    int fac; // product

    fac = 1;
    i = 1;
    while (i <= n) {
        fac = fac * i;
        i = i + 1;
    }
    return fac;
}
