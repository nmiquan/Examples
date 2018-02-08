// Sort n numbers using bubblesort
// Written by andrewt@cse, March 2017
// Modified by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>
#include "arraylib.h"

void bubbleSort(int a[], int n);

int main(int argc, char *argv[])
{
    int *numbers; // array[n] integers
    int  n;       // size of array
    char ord;     // order of values in array

    if (argc != 3
        || sscanf(argv[1],"%d",&n) != 1
        || sscanf(argv[2],"%c",&ord) != 1)
    {
        fprintf(stderr,
                "Usage: %s  N  Ord(r|a|d)\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    numbers = malloc(n * sizeof (int));
    if (numbers == NULL) {
        perror("");
        exit(EXIT_FAILURE);
    }

    insertValues(numbers, n, ord);
    printf("Original: ");
    showValues(numbers, n, 0, 14);
    printf("\n");

    bubbleSort(numbers, n);

    printf("Sorted: ");
    showValues(numbers, n, 0, 14);
    printf("\n");

    free(numbers);
    return EXIT_SUCCESS;
}

void bubbleSort(int a[], int n)
{
    int i;       // array index
    int swapped; // flag for whether swap happened

    swapped = 1;
    while (swapped) {
        swapped = 0; // assume no swaps will occur
        for (i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                int tmp;
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                swapped = 1;
            }
        }
    } 
}

