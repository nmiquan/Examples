// What's going on?
#include <stdio.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    int i;

    printf("Enter a single digit number: ");
    fgets(line, MAX_LINE, stdin);
    if (line[0] >= '0' && line[0] <= '9') {
        i = line[0] - '0';
        printf("You entered %d\n", i);
    }
    return 0;
}
