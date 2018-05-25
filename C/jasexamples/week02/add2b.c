// Add two numbers
// jas, Mar 17

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int x, y, sum;
    // get two numbers
    printf("Give me two numbers: ");
    if (scanf("%d:%d", &x, &y) != 2) {
        printf("Invalid number; giving up\n");
        return EXIT_FAILURE; // failure status
    }
    
    // add numbers together
    sum = x+y;
    
    // print sum
    printf("The sum of %d and %d is %d\n", x, y, sum);
    return EXIT_SUCCESS;
}
