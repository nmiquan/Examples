// A simple program demonstrating the use of scanf and if statements

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    if (a > b) {
        printf("a is greater than b\n");
    } else if (a < b) {
        printf(" a is less than b \n");
    } else {
        printf("a is equal to b\n");
    }
    return 0;
}
