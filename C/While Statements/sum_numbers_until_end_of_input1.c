// Read numbers until end of input (or a non-number) is reached then print sum of the numbers

// A simple program demonstrating stopping a while loop when scanf fails to read a number e.g. because end-of-input is reached

#include <stdio.h>

int main(void) {
    int sum, x, numbersRead;

    sum = 0;
    numbersRead = 1;
    printf("Enter numbers, indicate end-of-input with control-D:\n");

    // if scanf can read an integer it will place it in x and it will return 1
    // if scanf can't read an integer it wil not change x and it will return 0 or -1

    numbersRead = scanf("%d", &x);
    while (numbersRead == 1) {
        sum = sum + x;
        numbersRead = scanf("%d", &x);
    }
    printf("Sum of the number is %d\n", sum);
    return 0;
}

