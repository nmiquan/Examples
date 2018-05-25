// Search array of ints using linear search
// Written by andrewt@cse, April 2017
// Modified bu jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>
#include "arraylib.h"

int linearSearch(int a[], int n, int x);

int main(int argc, char *argv[])
{
    int *numbers; // array[n] integers
    int  n;       // size of array
    int  key;     // value to search for
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
    printf("Numbers: ");
    showValues(numbers, n, 0, 14);
    printf("\n");

    printf("Search for? ");
    while (scanf("%d", &key) == 1) {
        if (linearSearch(numbers, n, key) == 1) {
            printf("found\n");
        } else {
            printf("not found\n");
        }
        printf("Search for? ");
    }
    
    free(numbers);
    return 0;
}

int linearSearch(int a[], int n, int x)
{
    int i;       // array index
    int found;
    
    // for each item in array
    i = 0;  found = 0;
    while (!found && i < n) {
        // if found value x in item, stop search
        if (a[i] == x) found = 1;
        i++;
    }
    // if found return 1 else return 0
    if (found) {
        return 1;
    }
    else {
        return 0;
    }
}

