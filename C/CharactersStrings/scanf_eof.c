#include <stdio.h>

int main(void) {
    char num;
    // scanf returns the number of items read
    while (scanf("%s", &num) == 1) {
        printf("you entered the number: %s\n", num);
    }
    return 0;
}
