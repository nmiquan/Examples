// A simple program demonstrating the use of scanf and chained if statements

#include <stdio.h>

int main(void) {
    int herAge;
    printf("Hi George\n");
    printf("Enter her age: ");
    scanf("%d", &herAge);
    printf("George say this: \"");
    
    if (herAge < 17) {
        printf("Do you have an older sister?");
    } else if (herAge < 42) {
        printf("Would you like to go to a movie Saturday?");
    } else if (herAge < 65) {
        printf("Do you have a daughter?");
    } else {
        printf("Do you have a grand-daughter?");
    }
    printf("\"\n");
    return 0;
}

    
