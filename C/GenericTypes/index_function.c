// find the index of an item in an array

#include <stdio.h>

void *findIndex(void *array, size_t nelem, size_t size, int *index(void *, void *)) {
    char *arrayP = (char *)array;
    while (nelem > 1) {
        if (index(
    }
}

int findIndexChr(char item, char *array) {
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == item) return i; 
    } 
    return -1;
}

int findIndexInt(int item, int *array) {
    // assuming that end of int array is 0
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == item) return i;
    }
    return -1;
}

void main() {
    int arrayInt[] = {1,2,3,4,0};
    char *arrayChr[] = {"a","b","c","d","\0"};

    int indexInt;
    int indexChr;

    indexInt = findIndex(4, arrayInt, findIndexInt);
    indexChr = findIndex('b', arrayChr, findIndexChr); 

    printf("%d\n%d\n", indexInt, indexChr);
}
