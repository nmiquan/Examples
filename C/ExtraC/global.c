#include <stdio.h>

int x;

void f(int j) {
    x = j;
}

int main(void) {
    printf("%d\n", x); // prints 0
    f(42);
    printf("%d\n", x); // prints 42
    x = 1;
    printf("%d\n", x); // prints 1
    return 0;
}
