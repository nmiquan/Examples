#include <stdio.h>

#define SIZE 3

int read_square(int x[SIZE][SIZE]);
void print_square(int x[SIZE][SIZE]);

int main(void) {
    int x[SIZE][SIZE];
    int row, column;
    int is_magic_square = 0;
    printf("Enter %d numbers please:\n", SIZE*SIZE);
    if (read_square(x) != 1) {
        printf("Couldn't read square\n");
        return 1;
    }
    printf("Numbers are:\n");
    print_square(x);

    if (is_magic_square == 1) {
        printf("Is a magic square\n");
    } else {
        printf("Not a magic square\n");
    }
    return 0;
}

int read_square(int x[SIZE][SIZE]) {
    int row, column;
    row = 0;
    while (row < SIZE) {
        column = 0;
        while (column < SIZE) {
            if (scanf("%d", &x[row][column]) != 1) {
                return 0;
            }
            column = column + 1;
        }
        row = row + 1;
    }
    return 1;
}

void print_square(int x[SIZE][SIZE]) {
    int row, column;
    row = 0;
    while (row < SIZE) {
        column = 0;
        while (column < SIZE) {
            printf("%d ", x[row][column]);
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
}
