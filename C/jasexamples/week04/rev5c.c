// Read five numbers
// Print in reverse order (of reading)
// Check that the user entered five numbers
// Written by andrewt@cse, Mar 2017

#include <stdio.h>

#define N_NUMBERS 5

int main(void)
{
    int x[N_NUMBERS];  // array of int's
    int i, j;          // index variables
    int scanfFailed;   // flag variable

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    scanfFailed = 0;
    while (i < N_NUMBERS && scanfFailed == 0) {
        if (scanf("%d", &x[i]) != 1) {
            scanfFailed = 1;
        }
        i = i + 1;
        // i tells us how many values have been read
    }
    // if (scanfFailed == 1) {
    if (i < N_NUMBERS) {
        printf("Insuffcient numbers read\n");
    } else {
        printf("Numbers reversed are:\n");
        j = N_NUMBERS - 1;
        while (j >= 0) {
            printf("%d ", x[j]);
            j = j - 1;
        }
    }
    printf("\n");
    return 0;
}

