// Add two numbers
// Use a function to get the numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

int add(int,int);

int main(void)
{
    int x, y, sum;
    
    // get two numbers
    x = getNumber("Give me the first number");
    y = getNumber("Give me the second number");

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
