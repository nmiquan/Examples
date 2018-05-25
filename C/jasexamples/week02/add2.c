// Add two numbers
// jas, Mar 17

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv)
{
    int x, y, sum;
    // get two numbers
    printf("Give me the first number: ");
    scanf("%d", &x);
    printf("Give me the second number: ");
    scanf("%d", &y);
    // add numbers together
    sum = x+y;
    // print sum
    printf("The sum of %d and %d is %d\n", x, y, sum);
    return 0;
}
