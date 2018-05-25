#include <stdio.h>

void main() {
    int n = 6;
    int *p1; // pointer to an integer
    int **p2; // pointer to an integer pointer
    int **p3;
    int ***p4; // pointer to the pointer that points to an integer pointer
    int ****p5; // pointer to the pointer to the pointer to the pointer that points to an integer poitner

    p1 = &n;
    p2 = &p1;
    //p3 = &p2;
    p4 = &p2;
    p5 = &p4;

    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    //printf("p3 = %p\n", p3);
    printf("p4 = %p\n", p4);
    printf("p5 = %p\n", p5);

    printf("\nAddress of:\n");
    printf("p1 = %p\n", &p1);
    printf("p2 = %p\n", &p2);
    printf("p4 = %p\n", &p4);
    printf("p5 = %p\n", &p5);

    
    
}
