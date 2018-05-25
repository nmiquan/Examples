// A simple program which reads integers and if a composite number is read exist printing the factor

#include <stdio.h>

int main(void) {
    int n, possibleFactor, keepLooping;
    keepLooping = 1;
    while (keepLooping == 1) {
        printf("Enter a number: ");
        scanf("%d", &n);
        possibleFactor = 2;
        while (possibleFactor < n && keepLooping == 1) {
            if (n % possibleFactor == 0) {
                printf("%d is composite %d is a factor\n", n, possibleFactor);
                keepLooping = 0;
             }
             possibleFactor = possibleFactor + 1;
        }
    }
    return 0;
}
