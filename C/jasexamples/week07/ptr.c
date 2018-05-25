// Show some stuff about pointers
// Written by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int    a = 42;
    double b = 3.14;
    char   c = '!';
    int    d[10] = {9,8,7,6,5,4,3,2,1,0};

    printf("a has address=%p, value=%d\n", &a, a);
    printf("b has address=%p, value=%lf\n", &b, b);
    printf("c has address=%p, value=%c\n", &c, c);
    printf("d starts at address=%p\n", &d[0]);
    printf("d starts at address=%p\n", d);

    int i;
    for (i = 0; i < 10; i++)
        printf("d[%d] has address=%p, value=%d\n",
               i, &d[i], d[i]); 

    return EXIT_SUCCESS;
}
