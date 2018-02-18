// Read N, then read N numbers
// Print in reverse order (of reading)
// Written by andrewt@cse, Mar 2017

#include <stdio.h>

#define MAX_NUMBERS 10

int main(void)
{
    int x[MAX_NUMBERS]; // array of int's
    int i, j;           // index variables
    int howMany;        // # of numbers read

    printf("Read how many numbers? ");
    scanf("%d", &howMany);
    if (howMany > MAX_NUMBERS) {
        printf("I'm sorry, Dave. I'm afraid I can't do that.\n");
        printf("Reading %d numbers\n", MAX_NUMBERS);
        howMany = MAX_NUMBERS;
    }
    i = 0;
    while (i < howMany) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    printf("Numbers reversed are:\n");

    j = howMany - 1;
    while (j >= 0) {
        printf("%d ", x[j]);
        j = j - 1;
    }
    printf("\n");
    return 0;
}

