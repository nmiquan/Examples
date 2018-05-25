// Print the result of an integer division
//
// Written by andrewt@unsw.edu.au 6/3/2017
// Modified by jas@cse.unsw.edu.au 7/3/2017

#include <stdio.h>

int main(void)
{
    int x, y;

    // Get the numbers x and y
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    // Display x/y
    printf("%d/%d=%d\n", x, y, x/y);
    
    return 0;
}
