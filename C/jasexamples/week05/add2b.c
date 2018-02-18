// Add two numbers
// Use a function to get the numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

void add(int,int,int *);

int main(void)
{
    int x, y, sum;

    // get two numbers
    x = getNumber("Give me the first number");
    y = getNumber("Give me the second number");

    // add numbers together
    add(x,y,&sum);

    // print sum
    printf("Sum of %d + %d is %d\n", x, y, sum);
    return EXIT_SUCCESS;
}

void add(int a, int b, int *c)
{
    printf("I can see a variable at location %p\n",c);
    *c = a;
    *c = *c + b;
    return /*nothing*/ ;
}
