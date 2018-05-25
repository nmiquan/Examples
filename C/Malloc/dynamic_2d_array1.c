// USE AN ARRAY OF POINTERS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main(void) {
    int row = 10;
    int column = 20;
    int i, j;
    int **A;

    A = malloc(row*sizeof(int *));
    for (i = 0; i < row; i++) {
        A[i] = malloc(column * sizeof(int));
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (i == j) A[i][j] = 1;    
            else A[i][j] = 0;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%2d", A[i][j]);
        }
        printf("\n");
    }

    // REALLOCATION

    int **newA;
    row = 20;
    column = 40;

    newA = realloc(A, row*sizeof(int *));
    if (!newA) {
        perror("Failed to allocate memory\n");
        exit(1);
    }
    for (i = 0; i < row; i++) {
        newA[i] = malloc(column*sizeof(int));
    }

    A = newA;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (i == j) A[i][j] = 1;
            else A[i][j] = 0;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%2d", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < row; i++) {
        free(A[i]);
    }
    free(A);

    /*
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (i == j) newA[i][j] = 1;
            else newA[i][j] = 0;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%2d", newA[i][j]);
        }
        printf("\n");
    }
    */
}
