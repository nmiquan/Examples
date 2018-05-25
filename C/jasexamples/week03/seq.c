// Generate a sequence of integers
// in the range 1 .. limit
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "getNumber"

int main(void)
{
    int i;
    int limit;
    
    limit = getNumber("Upper bound");

    i = 1;
    while (i <= limit) {
        printf("%d ",i);
        i = i + 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}

