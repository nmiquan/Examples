#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void) {
    FILE* fp;
    char string[1024];
    int i;

    fp = fopen("data", "r");
    
    /*
    fscanf(fp,"%s\n", &string);
    for (i = 0; i < strlen(string); i++) {
        if (isalnum(string[i])) {
            printf("%c", string[i]);
        }
    }
    printf("\n");
    */

    while (fscanf(fp, "%s", &string) > 0) {
        for (i = 0; i< strlen(string); i++) {
            printf("%c", string[i]);
        }
        printf("\n");
    }
}

