// Test my string functions
//  John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[10], s2[8];
    
    // check whether string copy works
    strcpy(s1, "xyzzy!");
    printf("s1 = \"%s\"\n", s1);
    strcpy(s2, "xyzzy!");
    printf("s2 = \"%s\"\n", s2);
    
    // check whether string equality works
    if (s1 == s2) {
        printf("This should not print\n");
        printf("s1 and s2 are different objects\n");
    }
    if (strcmp(s1,s2) == 0) {
        printf("s1 and s2 contain the same string\n");
    }
    if (strcmp(s1,"xyz") != 0) {
        printf("s1 does not contain \"xyz\"\n");
    }
    if (strcmp("abc","def") < 0) {
        printf("abc < def\n");
    }
    printf("strcmp(s1,\"xyz\") = %d\n",
            strcmp(s1,"xyz"));
    return EXIT_SUCCESS;
}
