// A simple program to check Pythagorean identity
// Andrew Taylor - andrewt@unsw.edu.au
// 6/3/2017

// Demonstrates danger of use == with doubles
// e.g. enter 1 for theta

#include <stdio.h>
#include <math.h>

int main(void) {
    double theta, identity;

    printf("Enter theta: ");
    scanf("%lf", &theta);
    
    identity = 1.0 - (sin(theta)*sin(theta) + cos(theta)*cos(theta));

    if (identity == 0.0) {
        printf("Pythagorean identity true for %lf\n", theta);
    } else {
        printf("Pythagorean wrong by %g for %lf\n", identity,  theta);
    }
    
    return 0;
}
