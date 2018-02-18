// Reads lines of input until end-of-input
// Print snap! if two consecutive lines are identical
//
// Andrew Taylor - andrewt@unsw.edu.au
// 28/4/14

#include <stdio.h>
#include <string.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char lastLine[MAX_LINE];

    // read first line into array lastLine
    printf("Enter line: ");
    fgets(lastLine, MAX_LINE, stdin);

    printf("Enter line: ");
    while (fgets(line, MAX_LINE, stdin) != NULL) {

        if (strcmp(line, lastLine) == 0) {
            // lines are identical
            printf("Snap!\n");
        }

        strncpy(lastLine, line, MAX_LINE);

        printf("Enter line: ");
    }

    return 0;
}
