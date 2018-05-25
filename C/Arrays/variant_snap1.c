// A simple program which reads integers and prints exists if the same number is read twice 

// Note the use of returnto leave the main function and hence finish program execution

#include <stdio.h>

#define MAX_NUMBERS 100000

int main(void) {
    int numbers[MAX_NUMBERS];
    int nNumbersRead, i;

    nNumbersRead = 0;
    while (nNumbersRead < MAX_NUMBERS) {
        printf("Enter a number: ");
        if (scanf("%d", &numbers[nNumbersRead]) != 1) {
            return 0;
        }
        i = 0;
        while (i < nNumbersRead) {
            if (numbers[i] == numbers[nNumbersRead]) {
                printf("Snap!\n");
                return 0;
            }
            i = i + 1;
        }
        nNumbersRead = nNumbersRead + 1;
    }
    printf("Sorry my array is full I have to stop!\n");
    return 0;
}
