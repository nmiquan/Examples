#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("%d + %d = %d\n", x, y, x + y);
    return 0;
}
