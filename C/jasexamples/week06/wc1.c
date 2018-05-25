// COMP1511 lecture example
// Simple implementation of Unix wc command
// It counts lines, word & characters in the file specified as an argument
//
// This version uses fgetc, see also wc_fgets.c
// See later version for more sophisticated argument handling
//
// Andrew Taylor - andrewt@unsw.edu.au
// 14/3/17

#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 4096

void processStream(FILE *stream, char streamName[]) {
    int c, lastc, lineCount, wordCount, characterCount;

    lineCount = 0;
    characterCount = 0;
    wordCount = 0;

    lastc = ' ';
    c = fgetc(stream);

    while (c != EOF) {
        if (c == '\n') {
            lineCount = lineCount + 1;
        }
        if (isspace(c) && !isspace(lastc)) {
            wordCount = wordCount + 1;
        }
        characterCount = characterCount + 1;
        lastc = c;
        c = fgetc(stream);
    }

    if (!isspace(lastc)) {
            wordCount = wordCount + 1;
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
