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
#include <stdlib.h>

#define MAX_LINE 4096

// scan an open file called name,
//   counting chars, words, and lines
void processStream(FILE *stream, char *name);

int main(int argc, char *argv[])
{
    FILE *in;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    in = fopen(argv[1], "r");
    if (in == NULL) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    processStream(in, argv[1]);

    return EXIT_SUCCESS;
}

// scan an open file called name,
//   counting chars, words, and lines
void processStream(FILE *stream, char *streamName)
{
    int c, lastc, nLines, nWords, nChars;

    nLines = 0;
    nChars = 0;
    nWords = 0;

    lastc = ' ';
    c = fgetc(stream);

    while (c != EOF) {
        if (c == '\n') {
            nLines = nLines + 1;
        }
        if (isspace(c) && !isspace(lastc)) {
            nWords = nWords + 1;
        }
        nChars = nChars + 1;
        lastc = c;
        c = fgetc(stream);
    }

    if (!isspace(lastc)) {
            nWords = nWords + 1;
    }

    printf("%s contains %d lines %d words %d characters\n", streamName, nLines, nWords, nChars);
}
