// Print the result of an integer division

#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    
    if (y != 0) {
        printf("%d/%d=%d\n", x, y, x/y);
    } else {
        printf("Can't divide by zero sorry\n");
    }
    return 0;
}
