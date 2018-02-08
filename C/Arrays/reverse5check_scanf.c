// Read 5 numbers and print them in reverse order
// This version checks that the scanf was able to read the number

#include <stdio.h>

#define N_NUMBERS 5

int main(void) {
    int x[N_NUMBERS], i, j, scanfFailed;

    printf("Enter %d numbers: ", N_NUMBERS);
    i = 0;
    scanfFailed = 0;
    while (i < N_NUMBERS && scanfFailed == 0) {
        if (scanf("%d", &x[i]) != 1) {
            scanfFailed = 1;
        }
        i = i + 1;
     }
     if (scanfFailed == 1) {
         printf("Insufficient numbers read\n");
     } else {
         printf("Numbers reversed are:\n");
         j = N_NUMBERS - 1;
         while (j >= 0) {
             printf("%d\n", x[j]);
             j = j - 1;
         }
     }
     return 0;
}
