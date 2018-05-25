// Print first 1000 multiples of 13
// Generate-only version
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int currentNumber;

    // generates only multiples of 13
    currentNumber = 13;
    while ( currentNumber <= 13000 ) {
        printf("%d\n", currentNumber);
        currentNumber = currentNumber + 13;
    }

    return EXIT_SUCCESS;
}
