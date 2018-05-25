// Read numbers until a negative number is read then print the sum of the numbers (not including the negative number)

// In comparison of sum_until_negative0.c
// variable x is not initialized outside of the while loop
// This program has a scanf() outside of while loop
// In each while loop scanf() is called at the end of the while loop

// In sum_until_negative0.c
// No scanf() is outside of the while loop
// But variable x is initialized out side of the while loop
// scanf() is called at the beginning of the while loop

// These two program do the same thing
// Is there any situation that one is of better use than the other ?  

#include <stdio.h>

int main(void) {
    int x, sum;

    sum = 0;
    printf("Enter numbers, terminate with a negative number:\n");

    scanf("%d", &x);
    while (x >= 0) {
        sum = sum + x;
        scanf("%d", &x);
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}
