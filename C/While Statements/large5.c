// Read 5 numbers and print the largest
// how to print N_NUMBERS defined as below?

#include <stdio.h>

#define N_NUMBERS 5

int main(void) {
    int howManyNumbers, number, maximum;
    printf("Enter %d", N_NUMBERS);
    scanf("%d", &maximum);
    howManyNumbers = 1;
    while (howManyNumbers < N_NUMBERS) {
        scanf("%d", &number);
        if (number > maximum) {
            maximum = number;
        }
        howManyNumbers = howManyNumbers + 1;
    }
    printf("Largest is %d\n", maximum);
    return 0;
}
