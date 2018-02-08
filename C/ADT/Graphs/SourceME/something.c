#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void main() {
    bool **arr;
    arr = malloc(10 * sizeof(bool *));
    for (int i = 0; i < 10; i++) {
        arr[i] = malloc(sizeof(bool));
        arr[i][0] = false;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i][0]);
    }

    printf("\n");
}
