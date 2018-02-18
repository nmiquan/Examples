// Reverse numbers from stdin
// Written by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

int *expand(int [], int *);

int main(int argc, char *argv[])
{
    int *a;   // array of not-yet-determined size
    int  n;   // size of array
    int  i;   // index variable
    int  num; // next input value
    
    // Make a "large enough" array
    n = 10;
    a = malloc(n * sizeof(int)); // like a[10]
    if (a == NULL) {
        printf("Can't make array\n");
        return EXIT_FAILURE;
    }

    // Read numbers into array
    printf("Enter numbers:\n");
    i = 0;
    while (scanf("%d",&num) == 1) {
        // if array is full
        if (i == n) {
            // make it bigger
            a = expand(a, &n);
        }
        // read number into next a[i]
        a[i] = num;
        i = i + 1;
    }
    
    // Scan array backwards, printing
    for (i = i-1; i >= 0; i--) {
        printf("%d ",a[i]); 
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int *expand(int *old, int *n)
{
    int *new; int nn;
    // make a larger array, new[]
    nn = 2 * (*n);
    new = malloc(sizeof(int) * nn);
    
    // copy old[] to new[]
    int i;
    for (i = 0; i < *n; i++) {
         new[i] = old[i];
    }
    
    // WRONG! new = old;  // does not copy contents
    
    
    // set *n to size of new array
    *n = nn;
    
    // remove old array
    free(old);
    
    // return new[]
    return new;
}
