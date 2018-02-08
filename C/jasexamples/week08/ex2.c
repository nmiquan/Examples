#include <stdio.h>
#include <stdlib.h>

// {1,2,-3,4,5}
// {1,2,?,4,5}

// copy positive elements from array to positive, return number copied
int copy_positive(int array_length,
                  int array[array_length], 
                  int positive[array_length])
{
    int i;     // index for array[]
    int j = 0; // index for positive[]
    for (i = 0; i < array_length; i++) {
        if (array[i] > 0) {
            positive[j] = array[i];
            j++;
        }
    }
    return j;    
}

int main(void)
{
        int a[5] = {-2, 3, -5, 42, 42};
        // note: b[] cannot have more values than a[]
        // why not?
        int b[5]; 
        
        int c = copy_positive(5, a, b);
        for (int i = 0; i < c; i++) {
                printf("pos[%d] = %d\n",i,b[i]);
        }
        printf("\n");
        return 0;
}


