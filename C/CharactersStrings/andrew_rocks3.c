#include <stdio.h>

#define LENGTH 14

int main(void) {
    // if we don't specify the size of an array being initialized
    // C will make it big enough to hold all the initializing elements
    // (14 in this case)
    int asciiCodes[] = {'A', 'n', 'd', 'r', 'e', 'w', ' ', 'R', 'o', 'c', 'k', 's', '!', '\n'};
    int i;

    i = 0;
    while (i < LENGTH) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }
    return 0;
}
