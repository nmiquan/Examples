// read a text string, convert to int
// Andrew Taylor - andrewt@unsw.edu.au
// 24/4/13

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int string2int(char *str)
{
    // skip spaces, until digit
    // while more digits
    //     incorporate digit into value
    // return value
    return 0;
}


int main(void)
{
    char string[MAX_LINE]; // input
    int  number;           // output

    printf("Enter a number: ");
    fgets(string, MAX_LINE, stdin);

    number = string2int(string);

    printf("The number was: %d\n", number);
    return 0;
}
