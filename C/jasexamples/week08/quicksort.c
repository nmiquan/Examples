// Sort n numbers using quicksort
// Andrew Taylor - andrewt@unsw.edu.au
// 27/5/2017

#include <stdio.h>
#include <stdlib.h>

void randomInts(int a[], int n) {
    int i;
    for (i = 0; i < n; i = i + 1) {
        a[i] = rand() % (10 * n);
    }
}

int quicksortExecutions;

void quicksort1(int a[], int lo, int hi) {
        int i, j, pivotValue;

        if (lo >= hi) {
            return;
        }
        // start from left and right ends
        i = lo;
        j = hi;

        // use middle value as pivot
        pivotValue = a[(lo + hi) / 2];

        while (i < j) {

            // Find two out-of-place elements
            while (a[i] < pivotValue) {
                i = i + 1;
                quicksortExecutions = quicksortExecutions + 1;
            }
            while (a[j] > pivotValue) {
                j = j - 1;
                quicksortExecutions = quicksortExecutions + 1;
            }
            // and swap them over
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = i + 1;
                j = j - 1;
            }
        }
        quicksort1(a, lo, j);
        quicksort1(a, i, hi);
    }

void quicksort(int a[], int n) {
    quicksortExecutions = 0;
    quicksort1(a, 0, n - 1);
    fprintf(stderr, "quicksort: loop executed %d times\n", quicksortExecutions);
}

int main(int argc, char *argv[]) {
    int *numbers;
    int i, n;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);

    numbers = malloc(n * sizeof (int));
    if (numbers == NULL) {
        perror("");
        exit(1);
    }

    randomInts(numbers, n);
     printf("Numbers are: ");
    for (i = 0; i < n; i = i + 1) {
        printf(" %d", numbers[i]);
        if (i == 20) {
            printf(" ... ");
            i = n;
        }
    }
    printf("\n");

    quicksort(numbers, n);

    printf("Sorted numbers are: ");
    for (i = 0; i < n; i = i + 1) {
        printf(" %d", numbers[i]);
        if (i == 20) {
            printf(" ... ");
            i = n;
        }
    }
    printf("\n");

    free(numbers);
    return 0;
}
