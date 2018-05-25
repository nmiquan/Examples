// Sum the series 1 + 1/2 + 1/3 + 1/4 + ...
//
// Written by andrewt@unsw.edu.au  5/3/2017
// Modified by jas@cse.unsw.edu.au 7/3/2017

#include <stdio.h>

#define N_SERIES_TERMS 1000

int main(void)
{
    double n;       // repetition counter
    double sum;  // accumulated sum

    n = 1;
    sum = 0;
    while (n <= N_SERIES_TERMS) {
        sum = sum + 1/n;
        printf("sum + %lf -> %lf\n", (1/n), sum);
        // sum += 1.0/n;
        n = n + 1;
    }

    printf("1 + 1/2 + 1/3 + ... + 1/%d = %lf\n", N_SERIES_TERMS, sum);
    return 0;
}
