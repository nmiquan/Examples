#include <stdio.h>

// passing an array to a function is equivalent to passing a pointer
// to its first element so changes to the array in the function
// will be visible outside the function

// note the array size does not need to be specified
// for an array parameter
// but the function needs to know the arrays size
// so it is passed as a separate parameter

void exponentiate(double x, double powers[], int len) {
    int i;
    double power;
    power = 1; 
    i = 1;
    while (i < len) {
        power = power * x;
        powers[i] = power;
        i = i + 1;
    }
}


#define ARRAY_SIZE 10

int main(void) {
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
