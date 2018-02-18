#include <stdio.h>

int main(void) {
    int ch;

    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    ch = getchar();
    while (ch != EOF) {
        printf("you entered the character '%c' which has ASCII code %d\n", ch, ch);
        ch = getchar();
    }
    return 0;
}
