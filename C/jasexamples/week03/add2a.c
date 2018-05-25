// Add two numbers
// Use a function to get the numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>

int getNumber(char *);

int main(void)
{
    int x, y, sum;

    // get two numbers
    x = getNumber("Give me the first number");
    y = getNumber("Give me the second number");

    // add numbers together
    sum = x+y;

    // print sum
    printf("Sum of %d + %d is %d\n", x, y, sum);
    return EXIT_SUCCESS;
}

int getNumber(char *prompt)
{
    int nread, n;

    // print the prompt
    printf("%s: ", prompt);

    // attempt to read
    nread = scanf("%d", &n);
    if (nread != 1) {
        printf("Not a number\n");
        exit(EXIT_FAILURE);
    }
    return n;
}
