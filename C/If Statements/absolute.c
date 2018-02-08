// Convert a measurement in feet to metres
// A simple program demonstrating the use of scanf, print and an if statement

#include <stdio.h>

int main(void) {
    double x, absoluteValue;

    printf("Enter number: ");
    scanf("%lf", &x);
    
    absoluteValue = x;
    if (x < 0) {
        absoluteValue = -1.0 * x;
    }
    
    printf("The absoluate value of %f is %f\n", x, absoluteValue);
    return 0;
}
