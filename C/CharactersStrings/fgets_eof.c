#include <stdio.h>
#include <string.h>
#define MAX_LINE 1024

int main(void) {
    char line[MAX_LINE];

    // fgets returns NULL if it can't read any characters
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        printf("you entered the line: %s", line);
        printf("%d\n", strcmp(line, "abc\n"));
    }
    return 0;
}
