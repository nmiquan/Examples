// use a while loop to print first 1000 multiples of 13

#include <stdio.h>

int main(void) {
    int i;
    i = 1;
    while (i <= 13000) {
        if (i % 13 == 0) {
            printf("%d\n", i);
        }
        i = i + 1;
    }
    return 0;
} 
