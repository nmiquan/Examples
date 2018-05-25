// Read numbers until end of input (or non-number)
// then print the sum of the numbers
//
// Written andrewt@unsw.edu.au 23/3/2016
// Modified by jas@cse.unsw.ed.au 7/3/2017

#include <stdio.h>

int main(void)
{
    int sum, x;

    sum = 0;
    printf("Enter number: ");
    while (scanf("%d", &x) == 1) {
        sum = sum + x;
        printf("Enter number: ");
    }

    printf("\nSum of the numbers is %d\n", sum);
    return 0;
}
