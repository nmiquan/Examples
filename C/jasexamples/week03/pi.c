// Calculate pi to 8 decimal places
// by summing the series
// pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 + ...
// 
// Written by andrewt@unsw.edu.au 25/3/2016
// Modified by jas@cse.unsw.edu.au 7/3/2017

#include <stdlib.h>
#include <stdio.h>

#define N_TERMS_IN_SERIES 1000000

// Method: (4/1 - 4/3 + 4/5 - 4/7 + ...)
// pi_approx = 0
// foreach n in 1..100000 {
//    x = ...n...
//    if (n is even)
//       add 4/x to pi_approx
//    else
//       subtract 4/x from pi_approx
// }

int main(void)
{
    int n;
    double sum, x;

    ...

    printf("pi = %.8lf\n", sum);
    return 0;
}
