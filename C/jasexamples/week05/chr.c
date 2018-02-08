// Examine chars
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ascii;
    
    ascii = 0;
    while (ascii < 127) {
        printf("code %3d,", ascii); 
        if (!isprint(ascii))
            printf(" char Non-printing\n");
        else {
            printf(" char '%c',", ascii);
            if (isupper(ascii))
                printf(" upper case\n");
            else if (islower(ascii))
                printf(" lower case\n");
            else if (isdigit(ascii))
                printf(" digit\n");
            else if (ispunct(ascii))
                printf(" punctuation\n");
            else if (isspace(ascii))
                printf(" space\n");
            else
                printf(" dunno?\n");
        }
        ascii = ascii + 1;
    }
    return EXIT_SUCCESS;
}
