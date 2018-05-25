// Insertion Sort
// (1) Find the smallest element in the array, and exchange it with the element in the first position.
// (2) Find the second smallest element in the array and exchange it with the element in the second position.
// So on

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void selection(int *, int);
void print(int *, int);
void swap(int *, int *);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int a[], int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            printf("Iteration i = %d, j = %d\n", i, j);
            if (a[j] < a[i]) {
                printf("Index %d and %d are swapped\n", i, j);
                swap(&a[i], &a[j]);
            }
            print(a, length);        
            printf("\n");
        }
    }
}

void print(int a[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);    
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <randomize-input>\n", argv[0]);
        exit(1);
    } 

    int *arr;
    int size = 10;
    int i = 0;
    char line[1024];
    arr = malloc(size * sizeof(int)); 
    assert(arr != NULL);

    if (strcmp("random", argv[1]) == 0) {
        // generate randomized array
        for (; i < 10; i++) {
            arr[i] = rand() % 10 + 1; 
        }        

    } else if (strcmp(argv[1], "insert") == 0) {
        // insert number into the array
        while (fgets(line, 1024, stdin) != NULL) {
            if (i == size) {
                size = size * 2;
                arr = (int *)realloc(arr, size * sizeof(int));
                assert(arr != NULL);
            }
            arr[i] = atoi(line);
            i++;
        }
    }
    
    selection (arr, i);
    printf("Sorted array\n");
    print(arr, i);
    free(arr);
    return 1;

}
