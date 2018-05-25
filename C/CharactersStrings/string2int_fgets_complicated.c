#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(void) {
    char line[MAX_LINE];
    int i, n, powerOf10;

    printf("Enter a number: ");
    fgets(line, MAX_LINE, stdin);
    n = 0;
    i = 0;
    powerOf10 = 1;
    while (line[i] != '\n') {
        i = i + 1;
        powerOf10 = powerOf10 * 10;
    }
    powerOf10 = powerOf10 / 10;
    i = 0;
    while (line[i] != '\n') {
        // printf("i=%d line[i]%d\n", i, line[i]);
        n = n + powerOf10 * (line[i] - '0');
        i = i + 1;
        powerOf10 = powerOf10 / 10;
    }
    printf("You entered %d\n", n);
    return 0;
}
