// Read n numbers and print them in reverse order

#include <stdio.h>

#define MAX_NUMBERS 1000000

int main(void) {

    int x[MAX_NUMBERS], i, j, howMany;

    printf("Read how many numbers? ");
    scanf("%d", &howMany);
    if (howMany > MAX_NUMBERS) {
        printf("I'm sorry, Dave. I'm afraid I can't do that.\n");
        printf("Reading %d numbers\n", MAX_NUMBERS);
        howMany = MAX_NUMBERS;
    }

    i = 0;
    while (i < howMany) {
        scanf("%d", &x[i]);
        i = i + 1;
    }

    printf("Numbers reversed are:\n");
    j = howMany - 1;
    while (j >= 0) {
        printf("%d\n", x[j]);
        j = j - 1;
    }
    return 0;
}

