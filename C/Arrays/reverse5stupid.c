// Read 5 numbers and print them in reverse order - the hard way

// This approach quickly becomes impractical if you want to read more numbers
// a much better approach is to use an array

#include <stdio.h>

int main(void) {
    int x0, x1, x2, x3, x4;
    printf("Enter 5 numbers: ");
    scanf("%d", &x0);
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &x3);
    scanf("%d", &x4);
    printf("Numbers reversed are:\n");
    printf("%d\n", x4);
    printf("%d\n", x3);
    printf("%d\n", x2);
    printf("%d\n", x1);
    printf("%d\n", x0);
    return 0;
}

