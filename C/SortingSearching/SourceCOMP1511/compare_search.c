// Instrument linear search and binary search with an operation counter and compare their performance on a sorted arrays of random numbers.

#include <stdio.h>
#include <stdlib.h>

int linear_search(int array[], int length, int x);
int binary_search(int array[], int length, int x);
void quicksort(int array[], int length);
void quicksort1(int array[], int lo, int hi);
int partition(int array[], int lo, int hi);
void random_ints(int array[], int length);

int operation_counter;

int main(int argc, char *argv[]) {
    int *numbers;
    int i, length, x;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <array-size>\n", argv[0]);
        exit(1);
    }
    length = atoi(argv[1]);

    // use malloc to create an array so we can
    // because we may want an array too large to be a global variable

    numbers = malloc(length * sizeof(int));
    if (numbers == NULL) {
        perror("");
        exit(1);
    }

    random_ints(numbers, length);
    quicksort(numbers, length);

    printf("Array size is %d, elements are: ", length);

    for (i = 0; i < length; i = i + 1) {
        printf(" %d", numbers[i]);
        if (i == 20) {
            printf(" ... ");
            i = length;
        }
    }
    printf("\n");

    while (1) {
        printf("Search for? ");
        if (scanf("%d", &x) != 1) {
            free(numbers);
            return 0;
        }

        operation_counter = 0;
        printf("\nLinear search: ");
        if (linear_search(numbers, length, x) == 1) {
            printf("%d is in the numbers", x);
        } else {
            printf("%d is not in the numbers", x);
        }
        printf(" - search took %d operations\n", operation_counter);
        operation_counter = 0;
        printf("Binary serach: ");
        if (binary_search(numbers, length, x) == 1) {
            printf("%d is in the numbers", x);
        } else {
            printf("%d is not in the numbers", x);
        }
        printf(" - search took %d operations\n\n", operation_counter);
    }
}

int linear_search(int array[], int length, int x) {
    int i;
    for (i = 0; i < length; i = i + 1) {
        operation_counter++;
        if (array[i] == x) {
            return 1;
        }
    }
    return 0;
}

int binary_search(int array[], int length, int x) {
    int lower = 0;
    int upper = length - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        operation_counter++;
        if (array[mid] == x) {
            return 1;
        } else if (array[mid] > x) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    return 0;
}

void random_ints(int array[], int length) {
    for (int i = 0; i < length; i = i + 1) {
        array[i] = rand() % (10 * length);
    }
}

void sorted_random_ints(int array[], int length) {
    random_ints(array, length);
}

void quicksort(int array[], int length) {
    quicksort1(array, 0, length - 1);
}

void quicksort1(int array[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int p = partition(array, lo, hi);
    quicksort1(array, lo, p - 1);
    quicksort1(array, p + 1, hi);
}

int partition(int array[], int lo, int hi) {
    int i = lo;
    int j = hi;

    // use middle value as pivot
    int pivotValue = array[(lo + hi) / 2];

    //start from left and right ends
    while (i < j) {
        // Find two out-of-place elements
        while (array[i] < pivotValue) {
            i = i + 1;
            operation_counter++;
        }
        while (array[j] > pivotValue) {
            j = j - 1;
            operation_counter++;
        }
        // and swap them over
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    }
    return j;
}
