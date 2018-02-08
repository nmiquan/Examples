#include <stdio.h>

int main(void) {
    double fahrenheit, celsius;
    
    printf("Enter Fahrenheit temperature: ");
    scanf("%lf", &fahrenheit);
    celsius = 5.0 / 9.0 * (fahrenheit - 32);
    printf("%f Fahrenheit = %f Celsius\n", fahrenheit, celsius);
    return 0;
}
