// COMP1511 programming example
// Calculate the mathematical constant e by summing the series
// 1 + 1/1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4)  + ...
// http://en.wikipedia.org/wiki/E_%28mathematical_constant%29
//
// Written by Andrew Taylor,  5/3/2017
// Modified by John Shepherd, 7/3 2017
 //

#include <stdio.h>

// factorial function "signature"
// factorial : int -> int
int factorial(int);

#define N_SERIES_TERMS 8

int main(void)
{
    int n;         // loop counter
    double sum;    // sum of series
    double denom;  // current denominator

    n = 1;
    sum = 1;
    printf("1");
    while (n <= N_SERIES_TERMS) {
        denom = factorial(n);
        printf(" + 1/%.0lf", denom);
        // accumulate sum
        sum = sum + 1.0/denom;
        n = n + 1;
    }
    printf("\n\n");

    // display result
    printf("1 + 1/1 + 1/(1*2) + 1/(1*2*3) + ... = %.8lf\n", sum);
    return 0;
}

// compute n!
int factorial(int n)
{
    int i;   // current number
    int fac; // accumulated factorial

    i = 1;
    fac = 1;
    while (i <= n) {
        fac = fac * i;
        i = i + 1;
    }
    return fac;
}
