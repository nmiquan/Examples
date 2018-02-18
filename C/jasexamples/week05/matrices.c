// Functions on n x m matrices
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "matrices.h"
#include "johnslib.h"

// display a matrix, row-by-row
void showMatrix(int **m, int nRows, int nCols)
{
    int row;  // row index
    int col;  // column index

    //foreach row { foreach elem in row { ... } }
    row = 0;
    while (row < nRows) {
        col = 0;
        while (col < nCols) {
            printf("m[%d][%d] = %d\n",
                    row, col, m[row][col]);
            //printf("%3d", m[row][col]);
            col = col + 1;
        }
        row = row + 1;
        //printf("\n");
    }
}

// fill a matrix with values
void fillMatrix(int **m, int nRows, int nCols)
{
    int row;  // row index
    int col;  // column index
    
    row = 0;
    while (row < nRows) {
        printf("Enter %d values for row [%d]\n", nCols, row);
        col = 0;
        while (col < nCols) {
            m[row][col] = getNumber("Next");
            col = col + 1;
        }
        row = row + 1;
    }
}

// create an nRows x nCols matrix
int **makeMatrix(int nRows, int nCols)
{
    int row;  // row index
    int col;  // column index
    int **mat; // top left of matrix

    mat = malloc(nRows * sizeof(int *));
    for (row = 0; row < nRows; row++) {
        mat[row] = malloc(nCols * sizeof(int));
    }
    return mat;
}
