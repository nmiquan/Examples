#include <stdio.h>
#include <stdlib.h>
void main(void) {
    for(int i = 0; i < 10; i++) {
        printf("%d ", rand() % 10);
    }
    printf("\n");
}
