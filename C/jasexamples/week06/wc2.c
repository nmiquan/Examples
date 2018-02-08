// COMP1511 lecture example
// Simple implementation of Unix wc command
// It counts lines, word & characters from the files specified as arguments
//
// If no files are specified instead stdin is processed
// This allows use in a pipeline, e.g.:
// % gcc -Wall -O grep.c -o grep
// % gcc -Wall -O grep.c -o grep
// % gcc -Wall -O wc_fgetc1.c -o wc
// % ./grep return grep.c
// grep.c:30:        return 1;
// grep.c:38:                  return 1;
// grep.c:44:    return 0;
// % ./grep return grep.c | ./wc
// <stdin> contains 3 lines 9 words 85 characters
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
    int i;

    if (argc == 1) {
        // if no files are specified, process stdin
        processStream(stdin, "<stdin>");
    } else {
        for (i = 1; i < argc; i = i + 1) {
            in = fopen(argv[i], "r");
            if (in == NULL) {
                perror(argv[i]);
                return 1;
            }
            processStream(in, argv[i]);
        }
    }

    return 0;
}
