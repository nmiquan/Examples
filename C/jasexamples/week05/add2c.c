// Add two numbers
// Use argv[] to get the numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

int add(int,int);

int main(int argc, char *argv[])
{
    int x, y, sum;
    
    if (argc < 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    x = atoi(argv[1]);
    y = atoi(argv[2]);

    // add numbers together
    sum = add(x,y);

    // print sum
    printf("Sum of %d + %d is %d\n", x, y, sum);
    return EXIT_SUCCESS;
}

int add(int a, int b)
{
    return a+b;
    /*  
    int sum;
    sum = a + b;
    return sum;
    */
}
