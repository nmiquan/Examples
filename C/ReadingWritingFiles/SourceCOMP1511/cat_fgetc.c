// Simple implementation of reading files passed as command line arguments using fgetc - in other words cat

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *stream;
    int c;
    int i;
    for (i = 1; i < argc; i = i + 1) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]); // prints why the open failed
            exit(1);
        }
        c = fgetc(stream);
        while (c != EOF) {
            fputc(c, stdout);
            c = fgetc(stream);
        }
    }
    return 0;
}
