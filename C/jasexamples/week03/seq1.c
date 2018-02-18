// Generate a sequence of integers
// in the range 0 .. niter-1
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "getNumber"


int main(void)
{
    int n;
    int nIterations;
    
    nIterations = getNumber("# iterations");

    // common iteration pattern in C
    n = 0;
    while (n < nIterations) {
        printf("%d ",n);
        n = n + 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}

