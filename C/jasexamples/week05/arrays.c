// Functions on arrays
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

// Create an array of specified size
int *makeArray(int nElems)
{
    int *newArray;
    newArray = malloc(nElems*sizeof(int));
    if (newArray == NULL) {
        printf("Arrrrggggggghhh...\n");
        exit(EXIT_FAILURE);
    }
    return newArray;
}

// Read numbers into an array
// Parameters: array and #numbers
void fillArray(int *a, int nVals)
{
    int i;
    i = 0;
    while (i < nVals) {
        a[i] = getNumber("Next number");
        i = i + 1;
    }
    return;
}

// Sum numbers in an array
// Parameters: array and #numbers
int sumArray(int *a, int nVals)
{
    int i, sum;
    sum = 0;
    i = 0; 
    while (i < nVals) {
        sum = sum + a[i];
        i = i + 1;
    }
    return sum;
}
