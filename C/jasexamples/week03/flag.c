// Print a cross-pattern flag of size N
// All flags are N high, 3N wide
// N must be odd (or flag is ugly)
//
// Example for N = 5
// #######|#######
// #######|#######
// -------|-------
// #######|#######
// #######|#######
//
// John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>
#include "getNumber"

// for each row in 1..N
//    for each column in 1..3*N
//       print '#'
//    print '\n'

int main(void)
{
    int N;   // flag size
    int row; // current row
    int col;
    
    N = getNumber("Flag size (must be odd)");
    if (N%2 == 0) {
        printf("Must be odd flag size\n");
        return EXIT_FAILURE;
    }
    
    row = 1;
    while (row <= N) {
       // print a row
       col = 1;
       while (col <= 3*N) {
          if (col == 3*N/2+1)
              { printf("|"); }
          else if (row == N/2+1) // middle row
              { printf("-"); }
          else
              { printf("#"); }
          col = col + 1;
       }
       printf("\n");
       row = row + 1;
    }
    
    return EXIT_SUCCESS;
}
