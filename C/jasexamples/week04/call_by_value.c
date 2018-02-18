// Simple example illustrating call by value
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>

int f(int x)
{
    int y;
    // these assignments will have no effect on variables
    // outside the function
    x = x + 1;
    y = 3;
    printf("in f(): x=%d, y=%d\n", x, y);
    return x * y;
}

int main()
{
    int  x, y , z;
    x = 1;
    y = 2;
    z = f(y);
    // note the variables x & y are local to main
    // and are not changed by assignment to variables
    // of the same name in f()
    printf("in main(): x=%d y=%d z=%d\n", x, y, z);
    return 0;
}
