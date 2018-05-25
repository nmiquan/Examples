// Simple example illustrating passing an array to a function
// Andrew Taylor - andrewt@unsw.edu.au
// 17/03/17

#include <stdio.h>

double raise(double x, int n)
{
    int i;      // counter
    double pow; // product

    pow = 1.0;
    i = 0;
    while (i < n) {
        pow = pow * x;
        i = i + 1;
    }
    return pow;
}

// passing an array to a function is equivalent to passing a pointer
// to its first element so changes to the array in the function
// will be visible outside the function

// note the array size does not need to be specified
// in the array parameter's definition (so, powers[])
// but the function needs to know the array size
// so it is passed as a separate parameter

void exponentiate(double x, double powers[], int len)
{
    int i;
    i = 0;
    while (i < len) {
        powers[i] = raise(x,i);
        i = i + 1;
    }
}

#define ARRAY_SIZE 10

int main(void)
{
    int i;
    double powerArray[ARRAY_SIZE];

    exponentiate(42, powerArray, ARRAY_SIZE);
    i = 0;
    while (i < ARRAY_SIZE) {
        printf("42^%d = %lf\n", i, powerArray[i]);
        i = i + 1;
    }

    return 0;
}
