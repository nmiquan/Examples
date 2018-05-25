#include <stdio.h>

void main(void) {
    int a = 1;
    int b = 2;
    printf("a b\n");
    printf("%d %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("%d %d\n", a, b);
}
