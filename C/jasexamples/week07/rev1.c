// Reverse 10 numbers
// Written by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char *argv[])
{
    int a[N]; // array
    int  i;   // index variable
    
    // Read numbers into array
    printf("Enter 10 numbers:\n");
    i = 0;
    while (i < N) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Not enough numbers\n");
            exit(EXIT_FAILURE);
        }
        i = i + 1;
    }
    
    // Scan array backwards, printing
    for (i = N-1; i >= 0; i--) {
        printf("%d ",a[i]); 
    }
    printf("\n");
    return EXIT_SUCCESS;
}
