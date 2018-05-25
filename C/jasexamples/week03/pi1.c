// Calculate pi to 8 decimal places
// by summing the series
// pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 + ...
// 
// Written by andrewt@unsw.edu.au 25/3/2016
// Modified by jas@cse.unsw.edu.au 7/3/2017

#include <stdlib.h>
#include <stdio.h>

#define N_TERMS_IN_SERIES 100

int main(void)
{
    int n;      // loop counter
    int sign;   // +/- for next term
    int denom;  // denominator 1,3,5,7,...
    double sum; // accumulated sum (pi)

    n = 0;
    sign = 1;
    denom = 1;
    sum = 0;
    while (n < N_TERMS_IN_SERIES) {
        sum = sum + sign * 4.0/denom;
        n = n + 1;
        denom = denom + 2;
        if (sign == 1) { sign = -1; } else { sign = 1; }
        //printf("Current approx to pi: %.8lf\n", sum);
    }

    printf("pi = %.8lf\n", sum);
    return 0;
}
