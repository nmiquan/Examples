// Read lines until eof
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2017

#include <stdio.h>

#define MAX_LINE 1024

int main(void) 
{
    char line[MAX_LINE];
    int nlines = 0;

    // fgets returns NULL if it can't read any characters
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        //printf("you entered the line: %s", line);
        fputs(line, stdout);
        nlines = nlines + 1;
    }
    printf("%d lines \n", nlines);
    return 0;
}
