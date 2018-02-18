// A simple program which reads integers and prints snap and exists if the same number is read twice 

// This version uses a sentinel variable (stopNow)

// Why hasn't break statement been used?

#include <stdio.h>

#define MAX_NUMBERS 100000

int main(void) {
    int numbers[MAX_NUMBERS];
    int nNumbersRead, i, stopNow;

    nNumbersRead = 0;
    stopNow = 0;
    while (stopNow == 0) {
        printf("Enter a number: ");
        if (scanf("%d", &numbers[nNumbersRead]) != 1){
            stopNow = 1;
        } else {
            i = 0;
            while (i < nNumbersRead) {
                if (numbers[i] == numbers[nNumbersRead]){
                    printf("Snap!\n");
                    stopNow = 1;
                } 
                i = i + 1;
            }
            nNumbersRead = nNumbersRead + 1;
            if (nNumbersRead == MAX_NUMBERS) {
                printf("Sorry my array is full I have to stop!\n");
                stopNow = 1;
            }
        }
    }
    return 0;
}
