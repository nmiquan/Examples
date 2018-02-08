// Sort n numbers using quicksort
// Written by andrewt@cse, March 2017
// Modified by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>
#include "arraylib.h"

void quickSort(int a[], int n);

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

    quickSort(numbers, n);

    printf("Sorted: ");
    showValues(numbers, n, 0, 14);
    printf("\n");

    free(numbers);
    return EXIT_SUCCESS;
}

void doQuickSort(int a[], int lo, int hi)
{
    int i, j, pivotValue;

    if (lo >= hi) { // nothing to sort
        return;
    }
    
    // start from left and right ends
    i = lo;
    j = hi;

    // use middle value as pivot
    pivotValue = a[(lo + hi) / 2];

    while (i < j) {

        // Find two out-of-place elements
        while (a[i] < pivotValue) {
            i = i + 1;
        }
        while (a[j] > pivotValue) {
            j = j - 1;
        }
        // and swap them over
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    }
    doQuickSort(a, lo, j);
    doQuickSort(a, i, hi);
}

void quickSort(int a[], int n)
{
    doQuickSort(a, 0, n-1);
}
