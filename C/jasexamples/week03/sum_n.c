// Read n numbers and then print the sum of the numbers
//
// Written by andrewt@unsw.edu.au 23/3/2016
// Modified b jas@cse.unsw.edu.au  7/3/2017

#include <stdio.h>

int main(void)
{
    int x, sum, n, nNumbers;

    sum = 0;
    printf("How many numbers do you wish to sum: ");
    scanf("%d", &nNumbers);
    printf("Enter %d numbers:\n", nNumbers);

    n = 0;
    while (n < nNumbers) {
        scanf("%d", &x);
        sum = sum + x;
        n = n + 1;
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}
