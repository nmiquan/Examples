// Add numbers on command line
// Use argv[] to get the numbers
// jas, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "johnslib.h"

int main(int argc, char *argv[])
{
    int i, sum, val;
    
    if (argc < 3) {
        printf("Usage: %s num1 num2 ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // foreach elem of argv
    sum = 0;
    for (i = 1 ; i < argc ; i++) {
        //    convert from string to int
        if (sscanf(argv[i],"%d",&val) == 0) {
            printf("sum so far is %d\n", sum);
            printf("%s is not a number\n",argv[i]);
            return EXIT_FAILURE;
        } else {
            //    add into sum
            sum += val;
        }
    }
    printf("%d\n", sum);
    
    return EXIT_SUCCESS;
}
