// Simple example of using functions

#include <stdio.h>

void printManyMessages(int n);
void printMessages();

int main(int argc, char *argv[]) {
    int n;
    printManyMessages(1);
    printf("Repeat this how many times? ");
    scanf("%d", &n);
    printManyMessages(n);
    return 0;
}

void printManyMessages(int n) {
    while (n > 0) {
        printMessages();
        n = n - 1;
    }
}

void printMessages(void) {
    printf("C is good.\n");
    printf("C is great.\n");
    printf("We all love C.\n");
}
