// COMP1511 programming example
// Calculate the mathematical constant e by summing the series
// 1 + 1/1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4)  + ...
// http://en.wikipedia.org/wiki/E_%28mathematical_constant%29
//
// Written by Andrew Taylor,  5/3/2017
// Modified by John Shepherd, 7/3 2017
 //

#include <stdio.h>

#define N_SERIES_TERMS 8

int main(void)
{
    int n;          // loop counter
    double sum;     // sum of series
    double product; // current denominator

    n = 1;
    sum = 1;
    product = 1;
    printf("1");
    while (n <= N_SERIES_TERMS) {
        printf(" + 1/%.0lf", product);
        sum = sum + 1.0 / product;
        n = n + 1;
        product = product * n;
    }
    printf("\n\n");

    // display result
    printf("1 + 1/1 + 1/(1*2) + 1/(1*2*3) + ... = %.8lf\n", sum);
    return 0;
}
