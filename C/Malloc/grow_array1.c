#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array;
    int arraySize;
    int i, n;

    n = 0;
    arraySize = 4;
    array = malloc(arraySize * sizeof(int));
    if (array == NULL) {
        perror("");
        exit(1);
    }

    while (scanf("%d", &array[n]) == 1) {
        n = n + 1;
        if (n == arraySize) {
            // allocate larger array
            arraySize = 2 * arraySize;
            array = realloc(array, arraySize * sizeof(int));
            if (array == NULL) {
                perror("");
                exit(1);
            }
            printf("Array size increased to %d\n", arraySize);
        }
    }

    printf("Numbers reversed are:\n");
    for (i = n - 1; i >= 0; i = i - 1) {
        printf("%d\n", array[i]);
    }

    // free the allocated storage
    // this would happen on program exit anyway
    free(array);
    return 0;
}
