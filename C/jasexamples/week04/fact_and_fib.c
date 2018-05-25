// Simple recursive calculation of factorials & fibonacci numbers
// http://en.wikipedia.org/wiki/Factorial
// http://en.wikipedia.org/wiki/Fibonacci_number
//
// Fibonacci calculation is very inefficient
//
// Andrew Taylor - andrewt@unsw.edu.au
// 29/4/13

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
     if (n < 2) {
        return 1;
     }
     return fibonacci(n - 1) + fibonacci(n-2);
}

int factorial(int n) {
     if (n < 2) {
        return 1;
     }
     return n * factorial(n - 1);
}

int main(void) {
    int i = 1;
    while (i < 13) {
        printf("factorial(%d) = %d\n", i, factorial(i));
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
        i = i + 1;
    }
    return 0;
}
