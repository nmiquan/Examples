#include <stdio.h>

#define N_YEARS 10
#define SCALE 100

int main(void) {

    int whichYear[N_YEARS];
    double rainfall[N_YEARS];
    int year, asterisk, nAsterisks;

    printf("Enter %d years of rainfall totals\n", N_YEARS);

    year = 0;
    while (year < N_YEARS) {
        // This version always reads N_YEARS of rainfall
        printf("Enter year: ");
        scanf("%d", &whichYear[year]);
        printf("Enter rainfall(mm): ");
        scanf("%lf", &rainfall[year]);
        year = year + 1;
    }

    printf("\n1 asterisk == %d mm of rainfall\n", SCALE);

    year = 0;
    while (year < N_YEARS) {
        printf("%4d ", whichYear[year]);
        nAsterisks = rainfall[year] / SCALE;
        asterisk = 0;
        while (asterisk < nAsterisks) {
            printf("*");
            asterisk = asterisk + 1;
        }
        printf("\n");
        year = year + 1;
    }
    return 0;
}

