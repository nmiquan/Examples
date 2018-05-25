// Function to compute factorials
// http://en.wikipedia.org/wiki/Factorial
//
// n! = 1,        if n < 2
//    = n*(n-1)!, otherwise
//
// Written by andrewt@cse, April 2013

#include <stdio.h>
#include <stdlib.h>

// giveUp : String -> void
void giveUp(char *);

// factorial : Int -> Int
long int factorial(long int);

int main(int argc, char *argv[])
{
    int n;
    
	if ((argc < 2)) giveUp(argv[0]);
	
	if ((sscanf(argv[1], "%d", &n) != 1)) {
        giveUp(argv[0]);
    }

	printf("%d! = %ld\n", n, factorial(n));
    return EXIT_SUCCESS;
}

long int factorial(long int n)
{
    if (n < 2) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

void giveUp(char *cmdName)
{
    printf("Usage: %s Number\n", cmdName);
    exit(EXIT_FAILURE);
}
