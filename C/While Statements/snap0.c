// A simple program which reads integers and prints snap and exists if the same number is read twice in a row

#include <stdio.h>

int main(void) {
    int n, previousN;
    
    printf("Enter a number: ");
    scanf("%d", &previousN);

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != previousN) {
        previousN = n;
        printf("Enter a number: ");
        scanf("%d", &n);
     }
     printf("Snap!\n");
     return 0;
}
