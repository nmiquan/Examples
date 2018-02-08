#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int  nlines, nchars;
    
    nchars = nlines = 0;
    ch = getchar();
    while (ch != EOF) {
         nchars = nchars + 1;
         if (ch == '\n') {
             nlines = nlines + 1;
         }
         //putchar(ch);
         ch = getchar();
    }
    printf("%d chars, %d lines\n", nchars, nlines);
    return EXIT_SUCCESS;
}
