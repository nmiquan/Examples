#include <stdio.h>

int main(void) {
    int i;
    i = 1;
    while (i <= 1000) {
        printf("%d\n", i * 13);
        i = i + 1;
    }
    return 0;
}
