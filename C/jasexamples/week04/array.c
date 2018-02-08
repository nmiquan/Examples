// Array Demo
// Written by jas@cse, March 2017

#include <stdlib.h>
#include <stdio.h>

#define LEN 10

typedef char *String;

void showArray(String name, int arr[], int len)
{
    int i;
    printf("\nContents of %s[0..%d]\n\n", name, len-1);
    i = 0;
    while (i < len) {
        printf(" %s[%d] = %d\n", name, i, arr[i]);
        i = i + 1;
    }
    return;
}

void reverseArray(int arr[], int len)
{
    int i = 0;
    while (i < len/2) {
        int tmp;
        tmp = arr[i];
        arr[i] = arr[(len-1)-i];
        arr[(len-1)-i] = tmp;
        i = i + 1;
    }
 }

int main(void)
{
	int a[LEN] = {2,4,6,8,10,12,14,15,16};
	int b[LEN] = {3,5,7};
	int c[LEN] = {};

    showArray("a", a, LEN);
    //showArray("b", b, LEN);
    
    // reverse array a[]
    reverseArray(a, LEN);
    showArray("a'", a, LEN);
    
    //showArray("c", c, LEN);
	//showArray("a", a, 8);

    return EXIT_SUCCESS;
}
