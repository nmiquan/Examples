// Add two numbers
// jas, Mar 17

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv)
{
    int x, y, sum;
    // get two numbers
    printf("Give me the first number: ");
    if (scanf("%d", &x) == 0) {
        printf("Not a number; giving up\n");
        return 1;
    }
    else {
        printf("Thanks for typing %d\n",x);
    }
    printf("Second number: ");
    scanf("%d", &y);
    // add numbers together
    sum = x+y;
    // print sum
    printf("The sum of %d and %d is %d\n", x, y, sum);
    return 0;
}
