// Prints first 20 fibonacci numbers

#include <stdio.h>

int main(void) {
    int howManyNumbers, n, previousN, w;
    n = 1;
    previousN = 0;
    howManyNumbers = 0;
    while (howManyNumbers < 20) {
        w = previousN + n;
        previousN = n;
        n = w;
        howManyNumbers = howManyNumbers + 1;
        printf("%d\n", n);
    }
    return 0;
}       
