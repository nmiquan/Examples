// Read five numbers
// Print in reverse order (of reading)
// Written by andrewt@cse, Mar 2017

#include <stdio.h>

#define N_NUMBERS 10

int main(void)
{
    int x[N_NUMBERS] = {0}; // array of int's
    int i, j;         // index variables

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    while (i < N_NUMBERS) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    printf("Numbers reversed are:\n");
    j = N_NUMBERS - 1;
    while (j >= 0) {
        printf("%d ", x[j]);
        j = j - 1;
    }
    printf("\n");
    return 0;
}
