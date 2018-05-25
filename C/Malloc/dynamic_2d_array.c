// USE POINTER ARITHMETIC
// Why does having sizeof(int) in place of m yield a bug on A[0][5]? 
    

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void main(void) {
   int n = 4;
   int m = 6;
   int *A = malloc((n*m)*sizeof(int));
   assert(A != NULL);

   int i, j;

   for (i = 0; i < n; i++) {
       for(j = 0; j < m; j++) {
           if (i == j) {
               A[i*m + j] = 1;
           } else {
               A[i*m + j] = 0;
           }
           printf("%d %d %d\n", i, j, A[i *m + j]);
       }
       printf("\n");
   }

   printf("-------------------------------------------------\n");

   for (i = 0; i < n; i ++) {
       for (j = 0; j < m; j++) {
           printf("%d %d %d\n", i, j, A[i *m + j]);
           //printf("%2d", A[i*sizeof(int) + j]);
       }
       printf("\n");
   }

   printf("-------------------------------------------------\n");

   for (i = 0; i < (n * m); i++) {
       printf("%2d", A[i]);
   }

   printf("-------------------------------------------------\n");

   for (i = 0; i < n; i++) {
       for (j = 0; j < m; j++) {
           printf("%2d", A[i*m + j]);
       }
       printf("\n");
   }
   /*

   // REALLOCATING

   n = 20;

   int (*newA)[n];
   //newA = malloc(sizeof(int[n][n]));
   A = realloc(A, sizeof(int[n][n]));
   assert(A != NULL);

   for (i = 0; i < n; i++) {
       for( j = 0; j < n; j++) {
           if (i == j) A[i][j] = 1;
           else A[i][j] = 0;
       }
   }

   //A = newA;

   for (i = 0; i < n; i ++) {
       for (j = 0; j < n; j++) printf("%2d", A[i][j]);
       printf("\n");
   }
   */

   free(A);
}
