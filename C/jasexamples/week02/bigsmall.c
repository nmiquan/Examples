// Show whether a number is big/small
// and positive/negative
//
// Written by andrewt@unsw.edu.au, 18/3/2016
// Modified by jas@cse.unsw.edu.au, 7/3/2017

#include <stdio.h>

int main(void) 
{
    int a;
    printf("Enter a: ");
    scanf("%d", &a);

    printf("%d is a ", a);
    if (a < 0) {
        if (a < -100) {
            printf("big");
        } else {
            printf("small");
        }
        printf(" negative");
    } else {
        if (a > 100) {
            printf("big");
        } else {
            printf("small");
        }
        printf(" positive");
    }
    printf(" number.\n");

    return 0;
}
