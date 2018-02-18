// Simple implementation of reading files passed as command line arguments using fgets - in other words cat

#include <stdio.h>
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    FILE *stream;
    int i;
    for (i = 1; i < argc; i = i + 1) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]); // prints why the open failed
            return 1;
        }
        while (fgets(line, MAX_LINE, stream) != NULL) {
            printf("%s", line);
        }
    }
}
