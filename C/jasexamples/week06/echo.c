// Show command line arguments
// John Shepherd, March 2017

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (i < argc) {
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
        i = i + 1;
    }
    return EXIT_SUCCESS;
}
