// Read values into array and sum them
// Written by jas@cse, March 2017

#include <stdio.h>
#include <stdlib.h>
#include "johnslib.h"
#include "arrays.h"

int main(void)
{
    int *values;
    int total;
    int nVals;
    
    nVals  = getNumber("How big is the array");
    values = makeArray(nVals);
    printf("Enter %d values\n", nVals);
	fillArray(values, nVals);
	total = sumArray(values, nVals);
	printf("Total = %d\n", total);
    return EXIT_SUCCESS;
}
