// A simple program which prints a square

#include <stdio.h>

#define SIDE_LENGTH 13

int main(void) {
    int row, column;
    row = 0;
    while (row < SIDE_LENGTH) {
        column = 0;
        while (column <= SIDE_LENGTH) {
            printf("*");
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
    return 0;
}
