#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array;
    int *newArray;
    int arraySize, newArraySize;
    int i, n;

    n = 0;
    arraySize = 4;
    array = malloc(arraySize * sizeof(int));
    if (array == NULL) {
        perror("");
        exit(1);
    }

    while(scanf("%d", &array[n]) == 1) {
        n = n + 1;
        if (n == arraySize) {
            // allocate larger array
            newArraySize = 2 * arraySize;
            newArray = malloc(newArraySize * sizeof(int));
            if (newArray == NULL) {
                perror("");
                exit(1);
            }
            // copy contents of old array to new array
            for (i = 0; i < arraySize; i++) {
                newArray[i] = array[i];
            }
            // deallocate old array
            free(array);
            // change pointer to new array
            array = newArray;
            arraySize = newArraySize;
            printf("Array size increased to %d\n", arraySize);
        }
    }
    printf("Numbers reversed are:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d\n", array[i]);
    }
    // free the allocated storage
    // this would happen on program exit anyway
    free(array);
    return 0;
}
