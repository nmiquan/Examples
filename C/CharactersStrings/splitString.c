#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void main() {
    char *token, *string, *tofree;
    tofree = string = strdup("abc def 123");
    assert(string != NULL);
    
    while ((token = strsep(&string, " ")) != NULL)
        printf("%s\n", token);
        //printf("%d\n", strcmp(token, "abc"));

    free(tofree);
}
