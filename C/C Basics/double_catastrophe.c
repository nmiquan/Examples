#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y;
    x = 0.000000011;
    y = (1 - cos(x)) / (x * x);
    printf("correct answer = ~0.5 but y = %lf\n", y);
    return 0;
}
