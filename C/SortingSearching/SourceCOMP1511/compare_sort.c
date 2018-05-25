#include <stdio.h>
#include <stdlib.h>

// use a global varialbe to count operations
// at key points for both sorting algorithms

int operation_counter;

void bubblesort(int array[], int length);
void quicksort(int array[], int length);
void quicksort1(int array[], int lo, int hi);
int partition(int array[], int lo, int hi);
void random_ints(int array[], int length);

int main(void) {
    for (int n = 10; n <= 10000; n = n * 10) {
        int numbers1[n];
        int numbers2[n];

        random_ints(numbers1, n);
        for (int i = 0; i < n; i = i + 1) {
            numbers2[i] = numbers1[i];
        }

        printf("Array size %5d: ", n);
        operation_counter = 0;
        bubblesort(numbers1, n);
        printf(" bubblesort took %8d operations,", operation_counter);
        operation_counter = 0;
        quicksort(numbers2, n);
        printf(" quicksort took %6d operations\n", operation_counter);

        for (int i = 0; i < n; i = i + 1) {
            if(numbers2[i] != numbers1[i]) {
                printf("arrays differ at index %d\n", i);
                return 1;
            }
        }
    }
    return 0;
}

// https://en.wikipedia.org/wiki/Bubble_sort

void bubblesort(int array[], int length) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 1; i < length; i = i + 1) {
            operation_counter++;
            if (array[i] < array[i-1]) {
                int tmp = array[i];
                array[i] = array[i-1];
                array[i-1] = tmp;
                swapped = 1;
            }
        }
    }
}

// https://en.wikipedia.org/wiki/Quicksort

void quicksort(int array[], int length) {
    quicksort1(array, 0, length - 1);
}

void quicksort1(int array[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    // rearrange array so that
    // all elements smaller than pivot value are below it and
    // all element larger than pivot value are above it
    int p = partition(array, lo, hi);
    // sort lower part of array
    quicksort1(array, lo, p);
    // sort upper part of array
    quicksort1(array, p + 1, hi);
}

int partition(int array[], int lo, int hi) {
    int i = lo;
    int j = hi;

    // use middle value as pivot
    int pivotValue = array[(lo + hi) / 2];

    // start from left and right ends
    while (1) {
        // Look for pair to swap
        while (array[i] < pivotValue) {
            i = i + 1;
            operation_counter++;
        }

        while (array[j] > pivotValue) {
            j = j - 1;
            operation_counter++;
        }
        // No pair to swap so return
        if (i >= j) {
            return j;
        }
        // and swap them over
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i = i + 1;
        j = j - 1;
    }
}

void random_ints(int array[], int length) {
    for (int i = 0; i < length; i = i + 1) {
        array[i] = rand() % (10 * length);
    }
}
