#include <stdio.h>

#define MAXIMUM_YEARS 20000
#define SCALE 100

int main(void) {
    int whichYear[MAXIMUM_YEARS];
    double rainfal[MAXIMUM_YEARS];
    int year, asterisk, nAsterisks, nYears;


// This version asks the user how many years of rainfall they wish to plot
    printf("How many years of rainfall do you want to graph: ");
    scanf("%d", &nYears);
    if (nYears > MAXIMUM_YEARS) {
        printf("Limiting years read to maximum possible: %d\n", MAXIMUM_YEARS);
        nyears = MAXIMUM_YEARS;
    }

    year = 0;

    while (year < nYears) {
        printf("Enter year: ");
        scanf("%d", &whichYear[year]);
        printf("Enter rainfall(mm): ");
        scanf("%lf", &rainfall[year]);
        year = year + 1;
    }
    
    printf("\n1 asterisk == %d mm of rainfall\n", SCALE);

    year = 0;

    while (year < nYears) {
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
