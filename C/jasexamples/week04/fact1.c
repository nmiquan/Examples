// Function to compute factorials
// http://en.wikipedia.org/wiki/Factorial
//
// n! = 1,        if n < 2
//    = n*(n-1)!, otherwise
//
// Written by andrewt@cse, April 2013

#include <stdio.h>
#include <stdlib.h>

// factorial : int -> int
int factorial(int);

int main(void)
{
    int i = 1;
    while (i < 13) {
        printf("factorial(%d) = %d\n", i, factorial(i));
        i = i + 1;
    }
    return 0;
}

int factorial(int n)
{
    if (n < 2) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}
