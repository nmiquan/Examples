#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, j;
    i = 0;
    while (i < argc) {
        j = 0;
        while (argv[i][j] != '\0') {
            printf("argv[%d][%d]=%c\n", i, j, argv[i][j]);
            j = j + 1;
        }
        i = i + 1;
    }
    return 0;
}
