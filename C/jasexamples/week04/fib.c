// Function to compute fibonacci numbers
// http://en.wikipedia.org/wiki/Fibonacci_number
// NOTE: Fibonacci calculation is very inefficient
// Written by andrewt@cse, April 2013

#include <stdio.h>
#include <stdlib.h>

// fibonacci : int -> int
int fibonacci(int);

int main(void)
{
    int i = 1;
    while (i < 45) {
        printf("fibonacci(%d) = %d\n", 
                i, fibonacci(i));
        i = i + 1;
    }
    return 0;
}

int fibonacci(int n)
{
     if (n < 2) {
        return 1;
     }
     else {
         return fibonacci(n-1) + fibonacci(n-2);
     }
}
