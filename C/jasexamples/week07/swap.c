// Swap function ... swap values in two variables
// Written by andrewt@cse, April 2017
// Modified by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(int argc, char *argv[])
{
    int x = 42;
    int y = 13;

    printf("x=%d y=%d\n", x, y);
    
    swap(&x, &y);  // swap values in x and y
    
    printf("x=%d y=%d\n", x, y);
    return EXIT_SUCCESS;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
