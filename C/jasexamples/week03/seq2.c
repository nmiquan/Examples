// Generate a sequence of integers
// in the range lower .. upper
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "getNumber"


int main(void)
{
    int n;
    int lower_bound, upper_bound;
    
    lower_bound = getNumber("Lower bound");
    upper_bound = getNumber("Upper bound");

    if (lower_bound > upper_bound) {
        printf("ERROR: lower_bound > upper_bound\n");
        exit(EXIT_FAILURE);
    }

    n = lower_bound;
    while (n <= upper_bound) {
        printf("%d ",n);
        n = n + 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}
