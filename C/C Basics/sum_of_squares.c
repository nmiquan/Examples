#include <stdio.h>

int main(void){
    int x, y;
    int answer;

    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    answer = x * x + y * y;
    printf(" x squared + y squared = %d\n", answer);
    return 0;
}

