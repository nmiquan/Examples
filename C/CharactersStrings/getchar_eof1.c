#include <stdio.h>

int main(void) {
    int ch;

    // getchar returns an int which will contain either 
    // the ASCII code of the character read or EOF

    // using an assignment in a loop/if condition is
    // not recommended for novice programmers
    // but i used widely by experienced C programmers

    while ((ch = getchar()) != EOF) {
        printf("you entered the character: '%c' which has ASCII code %d\n", ch, ch);
    }
    return 0;
}
