// Reads lines of input untilend-of-input
// Print snap! if two consecutive lines are identical
//
// See snap_line2.c to see how to replace  compareArrays & copyArray
// calls to with (strcmp & strcpy) from <string.h>
//
// Andrew Taylor - andrewt@unsw.edu.au
// 28/4/14

#include <stdio.h>

#define MAX_LINE 4096

// return 1 if array1 & array2 differ in any element, 0 otherwise
// array1 & array2 must be null-terminated char arrays
// strcmp from  <string.h> performs similar functiom

int compareArrays(char array1[], char array2[]) {
    int i = 0;
    while (array1[i] != '\0') {
        if (array1[i] != array2[i]) {
            return 1;
        }
        i = i + 1;
    }
    if (array2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// copy elements in sourceArray to destinationArray
// sourceArray must be a null-terminated char array
// destinationArray must be large enough to hold string
// strcpy from  <string.h> performs the same function

void copyArray(char destinationArray[], char sourceArray[]) {
    int i = 0;
    while (sourceArray[i] != '\0') {
        destinationArray[i] = sourceArray[i];
        i = i + 1;
    }
    destinationArray[i] = '\0';
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char lastLine[MAX_LINE];

    // read first line into array lastLine
    printf("Enter line: ");
    fgets(lastLine, MAX_LINE, stdin);

    printf("Enter line: ");
    while (fgets(line, MAX_LINE, stdin) != NULL) {

        if (compareArrays(line, lastLine) == 0) {
            // lines are identical
            printf("Snap!\n");
        }

        copyArray(lastLine, line);

        printf("Enter line: ");
    }

    return 0;
}
