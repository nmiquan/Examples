// Miscellaneous functions
// John Shepherd, March 2017

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to read a number
//   in response to a prompt
// Terminates program, if not a number
// Returns number read, if is a number
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

// Copy string from one buffer to another
// s[] is the source array; t[] is the target array
void strcopy(char *t, char *s)
{
    int i;
    
    i = 0;
    while (s[i] != '\0') {
        // copy from s[i] to t[i]
        t[i] = s[i];
        i = i + 1;
    }
    t[i] = '\0';
}

// Compare two strings
int streq(char *s, char *t)
{
    int i;
    
    /*
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
    */
    i = 0;
    while (s[i] != '\0' && t[i] != '\0') {
        // check whether s[i] == t[i]
        if (s[i] != t[i]) {
            return 0;
        }
        i = i + 1;
    }
    /*
    if (s[i] == '\0' && t[i] == '\0')
        return 1;
    else
        return 0;
    */
    return (s[i] == t[i]);
}
