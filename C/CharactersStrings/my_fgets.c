#include <stdio.h>

#define MAX_LINE 4096

// fgets returns a pointer

char *myFgets(char array[], int arraySize) {
    int i, ch;
    i = 0;
    while (i < arraySize - 1) {
        ch = getchar();
        if (ch == EOF) {
            if (i == 0) {
                // no characters read
                // signal end-of-input
                return NULL;
            } else {
                array[i] = '\0';
                return array;
            }
        }
        array[i] = ch;
        if (ch == '\n') {
            array[i + 1] = '\0';
            return array;
        }
        i = i + 1;
    }
    // array full
    array[i] = '\0';
    return array;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    printf("Enter line: ");
    if (myFgets(line, MAX_LINE) != NULL) {
        printf("You entered: %s", line);
    }
    return 0;
}
