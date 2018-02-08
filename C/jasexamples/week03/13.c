// Print first 1000 multiples of 13
// Generate-and-test version
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int currentNumber;

    // generates all numbers 1..13000
    currentNumber = 1;
    while ( currentNumber <= 13000 ) {
        if (currentNumber % 13 == 0) {
            printf("%d\n", currentNumber);
        }
        currentNumber = currentNumber + 1;
    }

    return EXIT_SUCCESS;
}
