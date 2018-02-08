// COMP1911 lecture example
//
// Print "Andrew Rocks!" - using character constants to get the ASCII codes for the characters,
// and initialize the array to the vales array using , and print the array.
//
// This version has switched to using the numeric type char.  This type is almost
// always 8 bits and shouldn't be used for arithmetic.  It is commonly used
// to hold ASCII encodings.
//
//
// Andrew Taylor - andrewt@unsw.edu.au
// 9/4/2017

#include <stdio.h>

int main(void) {
    // if we don't specify the size of an array being initialized C will make
    // it big enough to hold all the initializing elements (15 in this case)
    char asciiCodes[] = {'A','n','d','r','e','w',' ','R','o','c','k','s','!','\n','\0'};
    int i;
    int posInts[] = {1,2,3,4,5,6,7,8,9,10};

    i = 0;
    while (asciiCodes[i] != '\n') {
        putchar(asciiCodes[i]);
        i = i + 1;
    }
    putchar(asciiCodes[i]);

    return 0;
}
