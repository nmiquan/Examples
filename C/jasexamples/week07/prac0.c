// Sample prac-exam-like problem
// Problem:
// - complete the function filterOdd(a,n)
// - which takes an array a containing n integers
// - modifies a[] to remove odd numbers
// - returns #values left in resulting array a[]
// Examples:
// a={1,2,3,4,5},  filterOdd(a,5) returns 2,  a'={2,4} 
// a={1,3,5,7},  filterOdd(a,4) returns 0,  a'={} 
// a={6,7,4,3,5,9,6,8},  filterOdd(a,8) returns 4,  a'={6,4,6,8} 


#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

int filterOdd(int *nums, int n);

int main(int argc, char *argv[])
{
    int a[MAX_NUMBERS]; // array of numbers
    int n;  // how many numbers in array
    int i;  // index variable

    // read numbers into array
    printf("Enter numbers:\n");
    i = 0;
    while (i < MAX_NUMBERS && scanf("%d",&a[i]) == 1) {
        i = i + 1;
    }
    n = i;

    // remove odd numbers from array
    n = filterOdd(a, n);

    // print resulting array
    for (i = 0; i < n; i++) {
       printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

// Removes odd numbers from array nums[n]
// Returns number of remaining values
int filterOdd(int *nums, int n)
{
    int *new;
    int i, j;
    
    new = malloc(n*sizeof(int)); // effectively int new[n]
    
    j = 0;
    for (i = 0; i < n; i++) {
        if (nums[i]%2 == 0) {
            new[j] = nums[i];
            j++;
        }
    }
    
    for (i = 0; i < j; i++) {
        nums[i] = new[i];
    }
    free(new);
    
    return j;
}
