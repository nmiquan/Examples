#include <stdio.h>

#define MAXIMUM_YEARS 20000
#define SCALE 100

int main(void) {
    int whichYear[MAXIMUM_YEARS];
    double rainfall[MAXIMUM_YEARS];
    int year, asterisk, nAsterisks;

    year = 0;
    while (year < MAXIMUM_YEARS) {
        printf("Enter year: ");
//This version reads years & their rainfall until end-of-file and puts -1 in the array as marker
        if (scanf("%d", &whichYear[year]) == 0) {
            whichYear[year] = -1;
            year = MAXIMUM_YEARS;
        } else {
            printf("Enter rainfall(mm): ");
            scanf("%lf", &rainfall[year]);
            year = year + 1;
        }
    }
    whichYear[MAXIMUM_YEARS - 1] = -1;

    printf("\n1 asterisk == %d mm of rainfall \n", SCALE);

    year = 0;
    while (whichYear[year] >= 0) {
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
