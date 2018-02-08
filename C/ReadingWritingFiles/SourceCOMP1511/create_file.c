#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *outputStream;
    outputStream = fopen("andrew.txt", "a");
    if (outputStream == NULL) {
        perror(argv[0]);
        return 1;
    }
    fprintf(outputStream, "andrew rules\n");
    fclose(outputStream);
    return 0;
}
