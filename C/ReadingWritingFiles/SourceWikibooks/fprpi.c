#include <stdio.h>

void main() {
    /* NUMBERS
    int n1 = 16;
    float n2 = 3.141592654f;
    FILE *fp;

    fp = fopen("data", "w");
    fprintf(fp, "   %d   %f", n1, n2);
    fclose(fp);
    */

    // STRING
    char string[] = "Hello\n Worldddd!\n               Hello World\nGoodBye\n";
    FILE *fp;

    fp = fopen("data", "w");
    fprintf(fp, "    %s", string);
    fclose(fp);
}
