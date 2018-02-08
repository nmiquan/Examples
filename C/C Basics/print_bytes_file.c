#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *stream;
    int c, i, j, byteCount;

    for (i = 1; i < argc; i = i + 1) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            perror(argv[i]); // prints why the open failed
            exit(1);
        }
        c = fgetc(stream);
        byteCount = 0;
        while (c != EOF) {
            printf("%s: byte %4d = ", argv[i], byteCount);
            j = 7;
            while (j >= 0) {
                printf("%d", (c >> j) & 1);
                j = j - 1;
            }
            printf("\n");
            c = fgetc(stream);
            byteCount = byteCount + 1;
         }
     }
     return 0;
}
        
