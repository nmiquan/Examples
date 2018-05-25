// Simple example illustrating use of pointers
// to return values from a function
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>
#include <stdlib.h>

void powers(double x, double square, double cube)
{
    square = x * x;
    cube = x * x * x;
}

int main(void)
{
    double s = 1, c = 2;

    powers(42, s, c);  // pass by reference

    printf("42^2 = %0.1lf\n", s);
    printf("42^3 = %0.1lf\n", c);

    return EXIT_SUCCESS;
}
