// arraylib.c: useful operations on arrays
// Written by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

// insertValues(a,n,ord)
// - fill array a[] of n elements with
//   set of distinct values in specified order
 
void insertValues(int a[], int n, char order)
{
    int i; // index
    int x; // current value
    if (order == 'a') {       // ascending
        x = rand() % 10;
        for (i = 0; i < n; i++) {
            a[i] = x;
            x = x + 1 + rand()%3;
        }
    }
    else if (order == 'd') {  // descending
        x = rand() % 10;
        for (i = n-1; i >= 0; i--) {
            a[i] = x;
            x = x + 1 + rand()%3;
        }
    }
    else {                    // random
        // generate ascending
        x = rand() % 10;
        for (i = 0; i < n; i++) {
            a[i] = x;
            x = x + 1 + rand()%3;
        }
        // then shuffle
        for (i = 0; i < n; i++) {
            int j, k, tmp;
            j = rand() % n;
            k = rand() % n;
            tmp = a[j]; a[j] = a[k]; a[k] = tmp;
        }
    }
}

// showValues(a[], n, lo, hi)
// - display values from a[lo] to a[hi]

void showValues(int a[], int n, int lo, int hi)
{
    int i;
    if (hi > n-1) hi = n-1;
    if (lo > 0) printf(" ...");
    for (i = lo; i <= hi; i = i + 1) {
        printf(" %d", a[i]);
    }
    if (n-1 > hi) printf(" ...");
}


