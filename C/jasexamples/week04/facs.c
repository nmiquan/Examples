// Function to compute factorials
// http://en.wikipedia.org/wiki/Factorial
// Written by andrewt@cse, April 2013

#include <stdio.h>
#include <stdlib.h>
#include "johnslib.h"

// gives enough info to use the factorial() function
// even though we don't have the function definition
// in this file
// int factorial(int);

int main(void)
{
    int i = 1;
    int max;
    max = getNumber("Max factorial");
    while (i <= max) {
        printf("factorial(%d) = %d\n", 
                 i, factorial(i));
        i = i + 1;
    }
    return 0;
}
