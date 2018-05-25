// Simple implementation of Unix wc command
// It counts lines, word & characters in the file specifed as an argument
// This version uses fgets

#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 4096

void processStream(FILE *stream, char streamName[]) {
    char line[MAX_LINE];
    int i, lineCount, wordCount, characterCount;

    lineCount = 0;
    characterCount = 0;
    wordCount = 0;

    while (fgets(line, MAX_LINE, stream) != NULL) {
        for (i = 0; line[i] != '\0'; i = i + 1) {
            if (i > 0 && isspace(line[i]) && !isspace(line[i-1])) {
                wordCount = wordCount + 1;
            }
            characterCount = characterCount + 1;
        }

        // This if handles case of line being longer than MAX_LINE
        if (!isspace(line[i-1])) {
            wordCount = wordCount + 1;
        } else if (line[i - 1] == '\n') {
            lineCount = lineCount + 1;
        }
    }
    
    printf("%s contains %d lines %d words %d characters\n", streamName, lineCount, wordCount, characterCount);
}

int main(int argc, char *argv[]) {
    FILE *in;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    in = fopen(argv[1], "r");
    if (in == NULL) {
        perror(argv[1]);
        return 1;
    }
    processStream(in, argv[1]);
    return 0;
}
