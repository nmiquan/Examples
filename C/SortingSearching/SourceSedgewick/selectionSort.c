#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

void selection(Item a[], int l, int r) {
    int i, j;
    for (i = l; i < r; i++) {
        int min = i;
        for (j = i+1; j < r; j++) {
            if (less(a[j], a[min])) min = j;
        exch(a[i], a[min]);
        }
    }
}

void main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <randomize>\n", argv[0]);
        exit(1);
    } 

    int *arr;
    char line[1024];
    arr = malloc(10 * sizeof(int)); 
    assert(arr != NULL);

    if (*argv[2] == 1) {
        // generate randomized array
        for (int i = 0; i < 10; i++) {
            arr[i] = (10)*rand();
        }        
    } else {
        int i = 0;
        while (fgets(line, 1024, stdin) != NULL) {
            arr[i] = atoi(line);
            i++;
        }
        // insert number into the array
    }

}
