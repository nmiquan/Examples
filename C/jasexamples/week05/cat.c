#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
         putchar(ch);
    return EXIT_SUCCESS;
}
