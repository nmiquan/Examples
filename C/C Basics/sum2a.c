#include <stdio.h>

int main(void) {
    int x, y, sum;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    sum = x + y;
    // These 6 printfs can be better replaced by a single printf
    printf("%d", x);
    printf(" + ");
    printf("%d", y);
    printf(" = ");
    printf("%d", sum);
    printf("\n");
    printf("\n");
    return 0;
}

