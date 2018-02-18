// COMP1511 lecture example
// Print lines containing specified pattern
//   from the files specified as arguments
//
// If no files specified, use stdin
//
// Note this code will produce incorrect results
//   if matched lines contain >= MAX_LINE chars
// Fixing this left as an exercise
//
// Andrew Taylor - andrewt@unsw.edu.au
// 14/3/17

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

// Scan a file called 'streamName'
//   which has been connected to 'stream'
// Look for lines containing 'searchFor'
// Show line numbers for all matching lines
void searchStream(FILE *stream, 
                  char *streamName, char *searchFor)
{
    // foreach line in stream
        // if line contains searchFor
            // print filename : line# : line
}

int main(int argc, char *argv[])
{
    FILE *in; // input stream
    int i;    // argv index

    if (argc < 2) {
        fprintf(stderr, 
                "Usage: %s <prefix> <files>\n",
                argv[0]);
        return EXIT_FAILURE;
    } 
    else if (argc == 2) {
        searchStream(stdin, "<stdin>", argv[1]);
    } 
    else {
        for (i = 2; i < argc; i++) {
            in = fopen(argv[i], "r");
            if (in == NULL) {
                perror(argv[i]);
                return EXIT_FAILURE;
            }
            searchStream(in, argv[i], argv[1]);
        }
    }
    return EXIT_SUCCESS;
}
