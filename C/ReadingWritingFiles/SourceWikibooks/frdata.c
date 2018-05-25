#include <stdio.h>
#include <string.h>

void main() {
    /* NUMBER
    int n1;
    float n2;
    FILE *fp;

    fp = fopen("data", "r");
    fscanf(fp, "%d %f", &n1, &n2);
    printf("%d %f\n", n1, n2);
    fclose(fp);
    */

    char string[2048];
    FILE *fp;

    fp = fopen("data", "r");
    while (fscanf(fp, "%s", string) != EOF) {
         printf("%s\n", string);
    }
    fclose(fp);
    
    for (int i = 0 ; i < strlen(string); i++) {
        printf("%c\n", string[i]);
    }
}

