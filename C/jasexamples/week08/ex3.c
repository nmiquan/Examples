#include <stdio.h>
#include <stdlib.h>

// Write function to find first and last positive
//  elements in array[]
// Set *first_positive & *last_positive to indices
//  of first & last postive numbers in array
// Return 1 if successful, return 0 otherwise
// Success == array contains a positive number
int find_first_last_positive(int array_length,
                             int array[],
                             int *first_positive,
                             int *last_positive)
{
    int first = -1;
    int last = -1;
    int i = 0;
    while (i < array_length) {
        if (array[i] > 0) {
                last = i;
                if (first == -1) {
                        first = i;
                }
        }
        i = i + 1;
    }
    if (first != -1) {
        *first_positive = first;
        *last_positive = last;
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    int a[5] = {-2, 3, -5, 41, 42};
    int f, l;
    int c = find_first_last_positive(5, a, &f, &l);
    printf("first +ve number a[%d] = %d\n", f,a[f]);
    printf("last +ve number a[%d] = %d\n", l, a[l]);
    return 0;
}
