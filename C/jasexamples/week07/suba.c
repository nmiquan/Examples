// Simple example illustrating use of pointers
// with array elements
// Written by andrewt@cse, April 2017
// Modified by jas@cse, April 2017

#include <stdio.h>
#include <stdlib.h>

void print_subarray(int array[],
                    int start, int length)
{
    int i;
    int *a = &array[start];
    // go to start of subarray
    // while not at end of subarray
        // print next element
        // if not last element, print ","
        // advance
    // end
    printf("\n");
}

int main(int argc, char *argv[])
{
    int nums[15] =
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int start, length;

    if (argc < 3) {
        printf("Usage: %s start length\n",argv[0]);
        return EXIT_FAILURE;
    }
    if (sscanf(argv[1],"%d",&start) != 1 ||
        sscanf(argv[2],"%d",&length) != 1) {
        printf("Start/length must be numbers\n");
        return EXIT_FAILURE;
    }

    printf("Entire array: ");
    print_subarray(nums, 0, 15);
    
    printf("Subarray of length %d ", length);
    printf("starting at index [%d]\n",start);
    printf("Your subarray: ");
    print_subarray(nums, start, length);

    return EXIT_SUCCESS;
}
