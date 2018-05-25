// Read numbers until end of input (or non-number)
// then print the average of the numbers
//
// Written andrewt@unsw.edu.au 23/3/2016
// Modified by jas@cse.unsw.ed.au 7/3/2017

#include <stdio.h>

int main(void)
{
    int sum, n, x;

    sum = 0;
    n = 0;
    printf("Enter number: ");
    while (scanf("%d", &x) == 1) {
        sum = sum + x;
        n = n + 1;
        printf("Enter number: ");
    }

    if (n > 0) {
        printf("\nMean = %lf\n", 1.0*sum/n);
    }
    return 0;
}
