#include <stdio.h>

int main(void) {
    // if we don't specify the size of an array being initialized C will
    // make it big enough to hold all the initializing elements (15 in this case)
    char asciiCodes[] = {'A', 'n', 'd', 'r', 'e', 'w', ' ', 'R', 'o', 'c', 'k', 's', '!', '\n', 0};
    int i;

    i = 0;
    while (asciiCodes[i] != 0) {
        putchar(asciiCodes[i]);
        i = i + 1;
    }
    return 0;
}
