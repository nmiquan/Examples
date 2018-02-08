// Function to compute factorials
// Written by andrewt@cse, April 2013

int factorial(int n)
{
    if (n < 2)
        return 1;
    else
        return n * factorial(n-1);
}
