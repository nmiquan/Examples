// This version has an extra special value in the array (0) to indicate the end of the sequence. This means we no longer have to keep track of how many characters in the array (note the while loop condition)

#include <stdio.h>

int main(void) {
    // if we don't specify the size of an array being initialized C will make
    // it big enough to hold all the initializing elements (15 in this case)
    int asciiCodes[] = {'A', 'n', 'd', 'r', 'e', 'w', ' ', 'R', 'o', 'c', 'k', 's', '!', '\n', 0};
    int i;

    i = 0;
    while (asciiCodes[i] != 0) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }	
    return 0;
}
