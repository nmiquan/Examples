// Simple example of cp command
// copy contents of file specified as first argument
// to file specified as 2nd argument
// Andrew Taylor - andrewt@unsw.edu.au
// 8/3/17

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *inputStream;
    FILE *outputStream;
    int  c; // current char

    // check that we have two file names
    if (argc < 3) {
        printf("Usage: %s inFile outFile\n",argv[0]);
        return EXIT_FAILURE;
    }

    // attempt to open argv[1] for reading
    // if can't open then give up
    if ((inputStream = fopen(argv[1],"r")) == NULL) {
        perror(argv[1]);
        return EXIT_FAILURE;
    }

    // attempt to open argv[2] for writing
    // if can't open then give up
    if ((outputStream = fopen(argv[2],"w")) == NULL) {
        perror(argv[2]);
        return EXIT_FAILURE;
    }

    // copy input to output
    
    while ((c = fgetc(inputStream)) != EOF) {
        fputc(c, outputStream);
    }

    // close files
    fclose(inputStream);
    fclose(outputStream);

    return EXIT_SUCCESS;
}
