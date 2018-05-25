// Print lines starting with specified string from specified files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

// test if str starts with prefix

int isPrefix(char prefix[], char str[]) {
    int length = strlen(prefix);
    return strncmp(prefix, str, length) == 0;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char *searchString;
    FILE *stream;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        exit(1);
    }
    searchString = argv[1];
    for (i = 2; i < argc; i = i + 1) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]);
            return 1;
        }
        while (fgets(line, MAX_LINE, stream) != NULL) {
            if (isPrefix(searchString, line)) {
                printf("%s", line);
            }
        }
    }
    return 0;
}
