// Add two numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int x, y, sum, nread;
    // get two numbers
    printf("Give me the first number: ");
    nread = scanf("%d", &x);
    if (nread != 1) {
        printf("Not a number\n");
        return EXIT_FAILURE;
    }
    printf("Give me the second number: ");
    nread = scanf("%d", &y);
    if (nread != 1) {
        printf("Not a number\n");
        return EXIT_FAILURE;
    }

    // add numbers together
    sum = x+y;

    // print sum
    printf("%d + %d = %d\n", x, y, sum);
    return EXIT_SUCCESS;
}
