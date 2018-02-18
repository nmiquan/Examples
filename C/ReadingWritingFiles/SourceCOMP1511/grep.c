// Print lines containing specified pattern from the files specified as arguments

// This verison provides the unix filter behaviour where if no files are specified it process stdin

// Note this code will produce incorrect results if matched lines contian >= MAX_LINE characters. Fixing this left as an exercise.

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void searchStream(FILE *stream, char streamName[], char searchFor[]) {
    char line[MAX_LINE];
    int lineNumber;

    lineNumber = 1;
    while (fgets(line, MAX_LINE, stream) != NULL) {
        if (strstr(line, searchFor) != NULL) {
            printf("%s:%d:%s", streamName, lineNumber, line);
        }
        lineNumber = lineNumber + 1;
    }
}

int main(int argc, char *argv[]) {
    FILE *in;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    }
    if (argc == 2) {
        searchStream(stdin, "<stdin>", argv[1]);
    } else {
        for (i = 2; i < argc; i = i + 1) {
            in = fopen(argv[i], "r");
            if (in == NULL) {
                perror(argv[i]);
                return 1;
            }
            searchStream(in, argv[i], argv[1]);
        } 
    return 0;
    }
}
