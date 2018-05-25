// Simple example of cp command copy contents of file specified as first argument to file specified as 2nd argument

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *inputStream;
    FILE *outputStream;
    int c;

    inputStream = fopen(argv[1], "r");
    if (inputStream == NULL) {
        perror(argv[1]);
        exit(1);
    }

    outputStream = fopen(argv[2], "w");
    if (outputStream == NULL) {
        perror(argv[0]);
        exit(1);
    }

    c = fgetc(inputStream);
    while (c != EOF) {
        fputc(c, outputStream);
        c = fgetc(inputStream);
    }

    fclose(outputStream);
    return 0;
}
