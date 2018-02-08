#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void) {
    FILE* fp;
    char string[1024];

    fp = fopen("data", "r");
    fgets(string, 1024, fp);
    fgets(string, 1024, fp);
    for (int i = 0; i < strlen(string); i++) {
        if (isalnum(string[i])) {
            printf("%c\n", string[i]);
        }
    }

    /*
    fgets(string, 1024, fp);
    printf("%s", string);
    fgets(string, 1024, fp);
    printf("%s", string);
    fgets(string, 1024, fp);
    printf("%s", string);
    fgets(string, 1024, fp);
    printf("%s", string);
    */

    /*
    while (fgets(string, 1024, fp) != NULL) {
        printf("%s\n", string);
    } 
    */
}
