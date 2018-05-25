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
    int mid;    // mid-point index
    int lower;  // lower index of array slice
    int upper;  // upper index of array slice
    int ncomps; // # comparisons
    
    lower = 0;
    upper = n-1;
    ncomps = 0;
    while (lower <= upper) {
        mid = (lower + upper)/ 2;
        ncomps++;
        if (x < a[mid]) {
            upper = mid - 1;
        } else if (x > a[mid]) {
            lower = mid + 1;
        }
        else { // x == a[mid]
            break;
        }
    }
    printf("%d compares\n", ncomps);
    return (x == a[mid]);
}

