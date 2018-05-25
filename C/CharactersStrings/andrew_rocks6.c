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
