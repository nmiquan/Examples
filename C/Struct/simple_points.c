#include <stdio.h>

struct Point {
    int x, y;
};

int main() {
    struct Point p1 = {0, 1};
    printf("x y\n");
    printf("%d %d\n", p1.x, p1.y);
    p1.x = 1;
    p1.y = 20;
    printf("%d %d\n", p1.x, p1.y);
}



