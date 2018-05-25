#include <stdio.h>
#include <stdlib.h>

void f(void)
{
    int a[10];
    // change function's return address on stack (gcc-6.3/Linux x86)
    // causing function to return after the line:  answer = 24
    // on CSE machines replace the following line with a[11] += 10;
    a[11] += 24;
}

int main(void)
{
    int answer = 42;
    f();
    answer = 24;
    printf("answer=%d\n", answer);
    return 0;
}
