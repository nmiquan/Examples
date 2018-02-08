#include <stdio.h>
#include <stdlib.h>

void f() {
    int i;
    int x = 99;
    int a[5] = {1,3,5,};

    for (i = 0; i < 15; i++) {
        if (0 < a[i] && a[i] < 1000)
            printf("%2d: Loc %p holds %d\n", i, &a[i], a[i]);
        else
            printf("%2d: Loc %p holds 0x%x\n", i, &a[i], a[i]);
    }
}

int main(void) {
    int a = 777;
    printf("function main is at address 0x%x\n", &main);
    printf("function f is at address 0x%x\n", &f);
    f();
    return 0;
}
