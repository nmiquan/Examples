// Search array of ints using binary search
// Written by andrewt@cse, April 2017
// Modified bu jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>
#include "arraylib.h"

int binarySearch(int a[], int n, int x);

int main(int argc, char *argv[])
{
    int *numbers; // array[n] integers
    int  n;       // size of array
    int  key;     // value to search for

    if (argc != 2
        || sscanf(argv[1],"%d",&n) != 1)
    {
        fprintf(stderr,
                "Usage: %s  N\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    numbers = malloc(n * sizeof (int));
    if (numbers == NULL) {
        perror("");
        exit(EXIT_FAILURE);
    }

    insertValues(numbers, n, 'a');
    printf("Numbers: ");
    showValues(numbers, n, 0, 14);
    printf("\n");

    printf("Search for? ");
    while (scanf("%d", &key) == 1) {
        if (binarySearch(numbers, n, key) == 1) {
            printf("found\n");
        } else {
            printf("not found\n");
        }
        printf("Search for? ");
    }
    
    free(numbers);
    return 0;
}

int binarySearch(int a[], int n, int x)
{
    int mid; // mid-point index
    int lo;  // lower index of array slice
    int hi;  // upper index of array slice
    
    lo = 0;
    hi = n-1;
    // while haven't exhausted focus
    while (lo <= hi) {
        // find mid point
        mid = (lo+hi)/2;
        
        // compare x to value at mid point
        // if smaller, focus on lower part of array
        if (x < a[mid]) {
            hi = mid - 1;
        }
        // if larger, focus on upper part of array
        else if (x > a[mid]) {
            lo = mid + 1;
        }
        // else found it, so stop search
        else {
            return 1;
        }
    }
    return 0;
}

