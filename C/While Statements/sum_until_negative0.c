// Read numbers until a negative number is read then print the sum of the numbers (not including the negative number)

// A simple program demonstrating stopping a while loop when a particular value is read by scanf

#include <stdio.h>

int main(void) {
    int x, sum;

    sum = 0;
    x = 0;
    printf("Enter numbers, terminate with a negative number:\n");

    while (x >= 0) {
        scanf("%d", &x);
        if (x > 0) {
            sum = sum + x;
        }
    }
    printf("Sum of the numbers is %d\n", sum);
    return 0;
}
