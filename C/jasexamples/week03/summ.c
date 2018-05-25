// Generate a sum of integers 1+2+...+limit
//
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "getNumber"

int main(void)
{
    int i;
    int limit;
    int sum;
    
    limit = getNumber("Upper bound");

    sum = 0;
    i = 1;
    while (i <= limit) {
        printf("%d",i);
        if (i < limit) {
            printf(" + ");
        }
        sum = sum + i;
        i = i + 1;
    }
    printf(" = %d\n",sum);
    return EXIT_SUCCESS;
}

