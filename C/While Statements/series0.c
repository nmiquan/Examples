#include <stdio.h>

#define N_SERIES_TERMS 1000

int main(void) {
    int n;
    double sum;
    n = 1;
    sum = 0;
    while (n <= N_SERIES_TERMS) {
        sum = sum + 1.0 / n;
        n = n + 1;
    }
    printf("1 + 1/2 + 1/3 + ... + 1/%d = %f\n", N_SERIES_TERMS, sum);
    return 0;
}
