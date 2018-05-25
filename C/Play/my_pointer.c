#include<stdio.h>

void main() {
    double a = 3;
    double* p1;
    double* p2;

    p1 = &a; // p1 points to a
    *p2 = a; // value at p2 is a

    printf("p1 = &a, p1's value is %p\n", p1);
    printf("*p2 = a, p2's value is %p\n", p2);
    printf("         value at p2 is %f\n", *p2);
    printf("         value at p1 is %f\n", *p1);
    printf("         &a's value is %p\n", &a);
}
