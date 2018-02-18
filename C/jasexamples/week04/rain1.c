// Read annual rainfall and plot as bar graph
// Written by andrewt@cse, March 2017

#include <stdio.h>

#define MAXIMUM_YEARS 1000
#define SCALE    100

int main(void)
{
    int    whichYear[MAXIMUM_YEARS];
    double rainfall[MAXIMUM_YEARS];
    int    i, nYears;     // index + counter
    int    j, nAsterisks; // index + counter

    printf("How many years of rainfall do you want to graph: ");
    scanf("%d", &nYears);
    if (nYears > MAXIMUM_YEARS) {
        printf("Limiting years read to  maximum possible: %d\n", MAXIMUM_YEARS);
        nYears = MAXIMUM_YEARS;
    }

    i = 0;
    while (i < nYears) {
        printf("Enter year: ");
        scanf("%d", &whichYear[i]);
        printf("Enter rainfall(mm): ");
        scanf("%lf", &rainfall[i]);
        i = i + 1;
    }

    printf("\n1 asterisk == %d mm of rainfall\n", SCALE);

    i = 0;
    while (i < nYears) {
        printf("%4d ", whichYear[i]);
        nAsterisks = rainfall[i] / SCALE;
        j = 0;
        while (j < nAsterisks) {
            printf("*");
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }

    return 0;
}

