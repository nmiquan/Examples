#include <stdio.h>

#define SIZE 8000

int main(void) {
    char x[SIZE];
    int nCharacters;
    printf("Enter some input: ");
    if (fgets(x, SIZE, stdin) == NULL) {
        printf("Could not read any characters\n");
        return 0;
    }

   // the builtin function strlen could be used here
   nCharacters = 0;
   while (x[nCharacters] != '\n' && x[nCharacters] != '\0') {
       nCharacters = nCharacters + 1;
   } 

   // if we don't find a newline - the whole line can't have been read
   if (x[nCharacters] != '\n') {
       printf("Could not read entire line\n");
       return 0;
   }

   printf("That line contained %d characters\n", nCharacters);

   if (nCharacters > 0) {
       printf("The first character was %c\n", x[0]);
       printf("The last character was %c\n", x[nCharacters-1]);
   }
   return 0;
}
