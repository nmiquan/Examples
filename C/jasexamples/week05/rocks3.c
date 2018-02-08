// COMP1911 lecture example
//
// Print "Andrew Rocks!" - using character constants to get the ASCII codes for the characters,
// and initialize the array to the vales array using , and print the array.
//
// C has a convenient shorthand for char arrays containing a sequence of
// ASCII codes with an extra 0 value marking the end of the sequence.
// Its "Andrew Rocks!";
//
//
// Compare the 8 andrew_rocks?.c programs which are all equivalent
// to get a better understand of how & why C encodes character sequences
//
// Andrew Taylor - andrewt@unsw.edu.au
// 9/4/2017

#include <stdio.h>

int main(void) {
    char asciiCodes[] = "Andrew Rocks!\n";
    int i;

    i = 0;
    while (asciiCodes[i] != 0) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }

    return 0;
}