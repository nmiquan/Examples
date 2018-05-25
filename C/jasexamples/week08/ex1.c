#include <stdio.h>
#include <stdlib.h>

// return a count of the number of positive ints in an array
int count_positive(int array_length, int array[])
{
    int i;
    int count = 0;
    for (i = 0; i < array_length; i++) {
        if (array[i] > 0) count++;
    }
    return count;
}

int main(void)
{
    int a[10] = { 1, 2, -3, 4, 5, -6, 7, 8, -9, -10 };
    int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int c[10] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };

    printf("Pos Ints in a[] = %d\n", count_positive(10,a));
    printf("Pos Ints in b[] = %d\n", count_positive(10,b));
    printf("Pos Ints in c[] = %d\n", count_positive(10,c));

    return 0;
}
