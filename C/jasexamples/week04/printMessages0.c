// Simple example of using functions
// Andrew Taylor - andrewt@unsw.edu.au
// 17/03/17

#include <stdio.h>

void printManyMessages(int n);
void printMessages();

int main()
{
    int n;
    printManyMessages(1);
    printf("Repeat this how many times? ");
    scanf("%d", &n);
    printManyMessages(n);
    return 0;
}

void printManyMessages(int n)
{
    while (n > 0) {
        printMessages();
        n = n - 1;
    }
}


void printMessages(void)
{
    printf("C is good.\n");
    printf("C is great.\n");
    printf("We all love C.\n");
}
