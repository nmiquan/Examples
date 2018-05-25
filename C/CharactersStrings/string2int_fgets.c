#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(void) {
    char line[MAX_LINE];
    int i, n;

    printf("Enter a number: ");
    fgets(line, MAX_LINE, stdin);
    n = 0;
    i = 0;
    while (line[i] > '0' && line[i] < '9') {
        n = 10 * n + (line[i] - '0');
        i = i + 1;
    }
    printf("You entered %d\n", n);
    return 0;
}
