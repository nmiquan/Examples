// invalid4.c ... example of buffer overflow

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int authenticated = 0;
    char password[8];

    printf("Enter your password: ");
    gets(password);
    
    if (strcmp(password, "secret") == 0) {
        authenticated = 1;
    }
    
    // a password longer than 8 characters will
    // overflow the array password[]
    // on gcc 6.3 on Linux/x86_64 this can
    // over write the variable authenticated
    // and allow access without knowing the
    // correct password

    if (authenticated) {
        printf("Welcome. You are authorized.\n");
    } else {
        printf("Unauthorized. Exterminate.\n");
    }
    
    return 0;
}
