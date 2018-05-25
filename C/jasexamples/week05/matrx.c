// Read and display a matrix
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "matrices.h"

int main(void)
{
	int **matrix;

    matrix = makeMatrix(3, 5);
    fillMatrix(matrix, 3, 5);
    showMatrix(matrix, 3, 5);
    return EXIT_SUCCESS;
}
