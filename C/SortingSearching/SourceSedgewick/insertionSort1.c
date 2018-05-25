#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

void sort(Item a[], int l, int r) {
    int i, j;
    for (i = l; i < r; i++) {
        for (j = i; j > 0; j--) {
            compexch(a[j-1], a[j]);
        }
    }
}

void main(int argc, char *argv[]){
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <array-size> <randomize>\n", argv[0]);
        exit(1);
    }
    int i = 0, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = malloc(N*sizeof(int));
    assert(a != NULL);
    if (sw)
        for (i = 0; i < N; i ++)
            a[i] = 1000*(1.0*rand()/RAND_MAX);
    else
        while (scanf("%d", &a[i]) == 1) i++;
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n");
    //sort(a, 0, N);
    //for (i = 0; i < N; i++) printf("%3d ", a[i]);
    //printf("\n");
}
