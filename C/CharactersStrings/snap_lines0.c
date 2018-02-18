#include <stdio.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    int differences, i;
    char line[MAX_LINE];
    char lastLine[MAX_LINE];

    // read first line into array lastLine
    printf("Enter line: ");
    fgets(lastLine, MAX_LINE, stdin);

    printf("Enter line: ");
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        i = 0;
        // count how many characters differ
        // between line & lastLine

        differences = 0;
        while (line[i] != '\0' && lastLine[i] != 0) {
            if (lastLine[i] != line[i]) {
                differences = differences + 1;
            }
            i = i + 1;
        }

        if (differences == 0) {
            // lines are identical
            printf("Snap!\n");
        }

        // arrays can't be assigned so copy elements
        // of lsat line to line using a loop
        i = 0;
        while (line[i] != '\0') {
            lastLine[i] = line[i];
            i = i + 1;
        }
        lastLine[i] = '\0';
        printf("Enter line: ");
    }
    return 0;
}
