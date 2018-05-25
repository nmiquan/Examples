// written by andrewt@cse.unsw.edu.au as a COMP15111 lecture example

#include <stdio.h>

void f(int x);

int main(void) {
    int answer = 36;
    f(5);
    printf("answer=%d\n", answer); // prints 42
    return 0;
}

void f(int x) {
    int a[10];
    
    // a[19] doesn't exist
    // with gcc 6.3 on Linux/x86_64 variable answer in main 
    // happens to be where a[19] would be
    a[19] = 42; 
}
