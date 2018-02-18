// Read numbers in the range 0..99
// Stop when  a number is read twice
// Ignores numbers not in 0..99
// Written by andrewt@cse, Mar 2017

#include <stdio.h>

#define LARGEST_NUMBER 99

int main(void)
{
    int i, n, snap;
    int numberCounts[LARGEST_NUMBER + 1];
    i = 0;
    while (i < LARGEST_NUMBER) {
       numberCounts[i] = 0;
       i = i + 1;
    }
    snap = 0;
    while (snap == 0) {
        printf("Enter a number: ");
        scanf("%d", &n);
        if (n < 0 || n > LARGEST_NUMBER) {
            printf("number has to be between 0 and 99 inclusive\n");
        } else {
            numberCounts[n] = numberCounts[n] + 1;
            if (numberCounts[n] > 1) {
                printf("Snap!\n");
                snap = 42;
            }
        }
    }

    return 0;
}

