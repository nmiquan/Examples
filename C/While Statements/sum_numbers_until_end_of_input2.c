// Read numbers until end of input (or a non-number) is reached then print the sum of the numbers

// A simple program demonstrating stopping a while loop when scanf fails to read a number e.g. because end-of-input is reached

#include <stdio.h>

int main(void) {
    int sum, x;

    sum = 0;

    printf("Enter number: ");
    while (scanf("%d", &x) == 1) {
        sum = sum + x;
        printf("Enter number: ");
    }
    printf("Sum of the number is %d\n", sum);
    return 0;
}
