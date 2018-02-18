// Simple implementation of reading files
// passed as command line arguments
// using fgetc - in other words cat
// Andrew Taylor - andrewt@unsw.edu.au
// 08/3/17

#include <stdio.h>
#include <stdlib.h>

void cat(FILE *);

int main(int argc, char *argv[])
{
    FILE *stream; // open file handle
    int i;        // index to argv[]

    if (argc == 1) {
        cat(stdin);
        return EXIT_SUCCESS;
    }
	// foreach A in command line args
	for (i = 1; i < argc; i++) {
        // attempt to open A for reading
        stream = fopen(argv[i], "r");
        // if can't open then give up
        if (stream == NULL) {
            perror(argv[i]);
            return EXIT_FAILURE;
        }
        cat(stream);
        fclose(stream);
    }

    return EXIT_SUCCESS;
}
        
void cat(FILE *stream)
{
    int c; // current char in file
    
    // scan and print file
    while ((c = fgetc(stream)) != EOF) {
        fputc(c, stdout);
    }  
}

