// Function to compute x^n
//   allows n to be -ve
// Written by jas@cse, March 2017

#include <stdio.h>
#include <stdlib.h>

// raise : real X int -> real
double raise(double,int);


int main(void)
{
    int n;     // power
    double x;  // base
    double x_to_n;

    n = 5;
    printf("Enter base: ");
    scanf("%lf", &x);
    printf("x = %0.2f\n", x);
    while (n >= -5) {
        x_to_n = raise(x, n);
        printf("x^%d = %0.5f\n", n, x_to_n);
        n = n - 1;
    }
    return 0;
}


double raise(double x, int n)
{
    int i;      // counter
    int isNeg;  // flag
    double pow; // product
/*
    if (n >= 0)
        isNeg = 0;
    else {
        isNeg = 1;
        n = -n;
    }
*/
    isNeg = (n < 0);
    if (isNeg) { n = -n; }
    pow = 1.0;
    i = 0;
    while (i < n) {
        pow = pow * x;
        i = i + 1;
    }
    if (isNeg) {
        pow = 1.0 / pow;
    }
    return pow;
}
