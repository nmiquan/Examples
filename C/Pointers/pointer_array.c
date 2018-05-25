#include <stdio.h>

int main(void) {
    int nums[7] = {5,6,7,8,9,10,11};
    int *n;
    char string[12] = "Hello World";
    char *s;

    n = &nums[3]; // n is address to the 4th element in the array
                  // increasing the index of n moves along the array
    printf("n[0]=%d n[1]=%d n[2]=%d\n\n", n[0], n[1], n[2]);

    s = &string[6];
    printf("string = %s\n", string);
    printf("s = %s\n", s);
    printf("&string[9] = %s\n\n", &string[9]);

    s = &string[2];
    s[2] = '\0'; // equivalent to string[4] = '\0'
    printf("string = %s\n", string);
    printf("s = %s\n", s);
    return 0;
}
