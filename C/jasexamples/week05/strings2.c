// Test my string functions
//  John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

int main(void)
{
    char s1[10], s2[8];
    
    // check whether string copy works
    mystrcopy(s1, "xyzzy!");
    printf("s1 = \"%s\"\n", s1);
    mystrcopy(s2, "xyzzy!");
    printf("s2 = \"%s\"\n", s2);
    
    // check whether string equality works
    if (s1 == s2) {
        printf("This should not print\n");
        printf("s1 and s2 are different objects\n");
    }
    if (mystreq(s1,s2)) {
        printf("s1 and s2 are equal\n");
    }
    if (mystreq(s1,"xyz")) {
        printf("s1 does not have \"xyz\"\n");
    }
    return EXIT_SUCCESS;
        
}
