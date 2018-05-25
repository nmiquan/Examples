#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *numbers;
    int i, n;

    printf("Read how many numbers? ");
    scanf("%d", &n);
    
    numbers = malloc(n * sizeof (int));
    if (numbers == NULL) {
        perror("");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Numbers reversed are:\n");
    for (i = n - 1; i >=0; i--) {
        printf("%d\n", numbers[i]);
    }

    // free the allocated storage
    // this would happen on program exit anyway
    free(numbers);
    return 0;
}

