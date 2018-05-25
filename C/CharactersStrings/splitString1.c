#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_LINE 1024

void main() {
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        char *token, *string;
        
        //tofree = string = strdup("abc def 123");
        string = line;
        assert(string != NULL);
        
        while ((token = strsep(&string, " ")) != NULL)
            printf("%s\n", token);
            //printf("%d\n", strcmp(token, "abc"));

    }
}
