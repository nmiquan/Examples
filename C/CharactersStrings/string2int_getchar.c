#include <stdio.h>

int main(void) {
    int n, c;
    printf("Enter a number: ");
    c = getchar();
    n = 0;
    while (c >= '0' && c <= '9') {
        n = 10 * n + (c - '0');
        c = getchar();
    }
    printf("You entered %d\n", n);
    return 0;
}
