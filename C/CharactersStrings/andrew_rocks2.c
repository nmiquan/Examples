// Print "Andrew Rocks!" - using character constants to get the ASCII codes for the characters, store them in array, and print the array. Note we have to track the array length.

#include <stdio.h>

#define LENGTH 14

int main(void) {
    int asciiCodes[14];
    int i;

    asciiCodes[0] = 'A';
    asciiCodes[1] = 'n';     
    asciiCodes[2] = 'd';
    asciiCodes[3] = 'r';
    asciiCodes[4] = 'e';
    asciiCodes[5] = 'w';
    asciiCodes[6] = ' ';
    asciiCodes[7] = 'R';
    asciiCodes[8] = 'o';
    asciiCodes[9] = 'c';
    asciiCodes[10] = 'k';
    asciiCodes[11] = 's';
    asciiCodes[12] = '!';
    asciiCodes[13] = '\n';

    i = 0;
    while (i < LENGTH) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }

    return 0;
}


