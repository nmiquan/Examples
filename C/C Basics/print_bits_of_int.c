#include <stdio.h>

int main(void) {
    int a, j;
    double something;
    while (1) {
        printf("Enter an int: ");
        scanf("%d", &a);
        j = 8 * (sizeof a);
        something = sizeof a;
        printf("size of a %lf\n", something);
        printf("Before reduced %d\n", j);
        while (j > 0) {
            j = j - 1;
            printf("%d\n", j);
            printf("\n");
            printf("%d", (a >> j) & 1);
        }
        printf("\n");
    }
    return 0;
}
