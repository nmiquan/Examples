#include <stdio.h>

#define SIZE 3

int main(void) {
    int x[SIZE][SIZE];
    int row, column;
    int magicConstant, sum;
    int notMagicSquare;

    // read potential magic square
    printf("Enter %d numbers please:\n", SIZE*SIZE);
    row = 0;
    while (row < SIZE) {
        column = 0;
        while (column< SIZE) {
            if (scanf("%d", &x[row][column]) != 1) {
                printf("Couldn't read enough numbers\n");
                return 0;
            }
            column = column + 1;
        }
        row = row + 1;
    }
    printf("Numbers are:\n");

    //print potential magic square
    row = 0;
    while (row < SIZE) {
        column  = 0;
        while (column < SIZE) {
            printf("%d ", x[row][column]);
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }

    // sum first row
    magicConstant = 0;
    row = 0;
    while (row < SIZE) {
        magicConstant = magicConstant + x[0][row];
        row = row + 1;
    }

    notMagicSquare = 0;
    // check if sum of each row matches sum of first row
    row = 1;
    while (row < SIZE) {
        sum = 0;
        column = 0;
        while (column < SIZE) {
            sum = sum + x[row][column];
            column = column + 1;
        }
        if (sum != magicConstant) {
            notMagicSquare = 1;
        }
        row = row + 1;
    }

    // check if sum of each columns matches sum of first row
    column = 0;
    while (column < SIZE) {
        sum = 0;
        row = 0;
        while (row < SIZE) {
            sum = sum + x[row][column];
            row = row + 1;
        }
        if (sum != magicConstant) {
            notMagicSquare = 1;
        }
        column = column + 1;
    }

    // check if sum of each diagonals matches sum of first row 
    
    column = 0;
    row = 0;
    sum = 0;
    printf("\n");
    // Is it a good practice?
    for(row, column; row < SIZE; row++, column++) {
        printf("%d %d %d\n", row, column, x[row][column]);
        sum += x[row][column]; 
    }

    if (sum != magicConstant) {
        notMagicSquare = 1;
    }

    printf("\n");

    column = SIZE-1;
    row = 0;
    sum = 0;
    for (row, column; row < SIZE; row ++, column--) {
        printf("%d %d %d\n", row, column, x[row][column]);
        sum += x[row][column];
    }
    
    if (sum != magicConstant) {
        notMagicSquare = 1;
    }

    // Ending prompt

    if (notMagicSquare == 0) {
        printf("Is a magic square\n");
    } else {
        printf("Not a magic square\n");
    }
    return 0;
}
