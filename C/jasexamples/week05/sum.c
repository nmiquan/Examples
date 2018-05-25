// Read values into array and sum them
// Written by jas@cse, March 2017

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

#define ARRAY_SIZE 10

int main(void)
{
    int values[ARRAY_SIZE];
    int total;

    printf("Enter %d values\n", ARRAY_SIZE);
	fillArray(&values[0], ARRAY_SIZE);
	total = sumArray(&values[0], ARRAY_SIZE);
	printf("Total = %d\n", total);
    return EXIT_SUCCESS;
}
