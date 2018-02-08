// Reverse N numbers
// Written by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *a;  // array of not-yet-determined size
    int  n;  // size of array
    int  i;  // index variable
    
    // work out how many numbers
    if (argc < 2) {
        printf("Usage: %s HowMany\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (sscanf(argv[1],"%d",&n) != 1 || n < 1) {
        printf("Usage: %s PositiveInteger\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /// Make a large enough array
    a = malloc(n * sizeof(int)); // like a[n]
    if (a == NULL) {
        printf("Can't make array\n");
        return EXIT_FAILURE;
    }

    // Read numbers into array
    printf("Enter %d numbers:\n", n);
    i = 0;
    while (i < n) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Not enough numbers\n");
            exit(EXIT_FAILURE);
        }
        i = i + 1;
    }
    
    // Scan array backwards, printing
    for (i = n-1; i >= 0; i--) {
        printf("%d ",a[i]); 
    }
    printf("\n");
    return EXIT_SUCCESS;
}
