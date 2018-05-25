// Function to compute x^n
// Written by jas@cse, March 2017

#include <stdio.h>
#include <stdlib.h>

// raise : real x int -> real
double raise(double,int);


int main(void)
{
    int n;     // power
    double x;  // base
    double x_to_n;

    n = 0;
    printf("Give me the base: ");
    scanf("%lf", &x);
    printf("x = %0.2f\n", x);
    while (n < 10) {
        x_to_n = raise(x, n);
        printf("x^%d = %0.5f\n", n, x_to_n);
        n = n + 1;
    }
    return 0;
}


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
