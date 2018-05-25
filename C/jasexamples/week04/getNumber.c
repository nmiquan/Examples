// Function to read a number
//   in response to a prompt
// Terminates program, if not a number
// Returns number read, if is a number
// John Shepherd, March 2017

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int getNumber(char *prompt)
{
    int nread, n;

    // print the prompt
    if (isatty(0)) {
        printf("%s: ", prompt);
    }

    // attempt to read
    nread = scanf("%d", &n);
    if (nread != 1) {
        printf("Not a number\n");
        exit(EXIT_FAILURE);
    }
    return n;
}
