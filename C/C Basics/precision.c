#include <stdio.h>

int main(void) {
    double a, b, c;
    a = 0.1;
    c = a + a + a + a + a + a + a + a + a + a;
    b = 1 - (a + a + a + a + a + a + a + a + a + a);
    printf("c value is %g\n", c);
    printf("b value is %g\n", b);
    return 0;
}
