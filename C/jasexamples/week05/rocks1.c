// COMP1911 lecture example
//
// Print "Andrew Rocks!" - using character constants to get the ASCII codes for the characters
//
// 'A' is the C shorthand for the ASCII code for the character A (65)
//
// Andrew Taylor - andrewt@unsw.edu.au
// 9/4/2017

#include <stdio.h>

int main(void) {
    putchar('A');   // equivalent to putchar(65)
    putchar('n');
    putchar('d');
    putchar('r');
    putchar('e');
    putchar('w');
    putchar(' ');
    putchar('R');
    putchar('o');
    putchar('c');
    putchar('k');
    putchar('s');
    putchar('!');
    putchar('\n');
    return 0;
}
