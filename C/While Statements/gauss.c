#include <stdio.h>

int main(void) {
    int n, upperBound, sum;
    sum = 0;
    upperBound = 10;
    n = 1;
    while (n <= upperBound) {
        sum = sum + n;
        printf("%d    %d\n", sum, n);
        n = n + 1;
    }
    printf("Sum of integers 1..%d is %d\n", upperBound, sum);
    return 0;
}
