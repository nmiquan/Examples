// Print pythagorean triples
// i.e. x,y,z  s.t.  x*x + y*y == z*z
// Andrew Taylor, March 2017
// Modified by John Shepherd, March 2017

#include <stdlib.h>
#include <stdio.h>

#define N 20

// Method:
// foreach triple x,y,z {
//     if x*x+y*y == z*z {
//         print x,y,z
//     }
// }

int main(void)
{
    int x, y, z;
    x = 1;
    while (x < N) {
        y = 1;
        while (y <= N) {
            z = 1;
            while (z <= N) {
                if (x * x + y * y == z * z) {
                    printf("%d^2 + %d^2 = %d^2\n", x, y, z);
                }
                z = z + 1;
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return EXIT_SUCCESS;
}
