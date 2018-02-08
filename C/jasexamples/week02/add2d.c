// Add two numbers
// jas, Mar 17

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int    howManyRead;  // how many ints did scanf find
	int    gotNumbers;   // did it find enough?
    double x, y;         // input numbers
	double sum;          // holds result
    // get two numbers
    printf("Give me two numbers: ");
    howManyRead = scanf("%lf %lf", &x, &y);
	gotNumber = (howManyRead == 2);

	if (! gotNumbers)
        printf("Invalid number; giving up\n");
        return EXIT_FAILURE; // failure status
    }
    
    // add numbers together
    sum = x+y;
    
    // print sum
    printf("The sum of %3.2lf and %8.3lf is %0.3lf\n", x, y, sum);
    return EXIT_SUCCESS;
}
