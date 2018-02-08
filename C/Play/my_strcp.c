#include <stdio.h>
#include <string.h>

void main(void) {
    char a[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char b[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char c[8];
    char d[6];

    printf("%d\n", a == b);
    strcpy(c, a);
    strcpy(d, a);
    printf("%d\n", a == c);
    printf("%d\n", a == d);

    printf("\n\n \"hello!\" == \"hello!\" is  %d \n", "hello!" == "hello!");
    
}
