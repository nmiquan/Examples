// Read five numbers
// Print in reverse order (of reading)
// Written by andrewt@cse, Mar 2017

#include <stdio.h>

int main(void) {
    int x0, x1, x2, x3, x4;
    printf("Enter 5 numbers: ");
    scanf("%d", &x0);
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &x3);
    scanf("%d", &x4);
    printf("Numbers reversed are:\n");
    printf("%d ", x4);
    printf("%d ", x3);
    printf("%d ", x2);
    printf("%d ", x1);
    printf("%d ", x0);
    printf("\n");
    return 0;
}

