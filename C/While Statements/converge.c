// Calculate the series 1 + 1/2 + 1/4 + 1/8 + ... until it converges to within 10 decimal places

#include <stdio.h>
#define ACCURACY 0.000000000001

int main(void) {
    double sum, term;

    sum = 0;
    term = 1;

    while (term > ACCURACY) {
        sum = sum + term;
        term = term / 2.0;
    }
    printf("1 + 1/2 + 1/4 + 1/8 + ... = %.10f\n", sum);
    return 0;
}
