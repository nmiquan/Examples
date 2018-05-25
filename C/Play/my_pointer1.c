#include <stdio.h>

int main()
{
    int x;
    int *p;

    p = &x;
    if (scanf("%d\n", &x) == 1) {
        printf("&x is %p\n", &x);
        printf(" p is %p\n", p);
        printf("*p is %d\n", *p);
        printf(" x is %d\n", x);
    }
}
