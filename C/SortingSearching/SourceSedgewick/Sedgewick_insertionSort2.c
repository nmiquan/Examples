// Adaptive insertion sort

#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
void insertion(Item a[], int l, int r)
  { int i;
    // moving the smallest item to the first index
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    //for (i = 0; i < r+1; i++) printf("%3d ", a[i]);
    //printf("\n");
    for (i = l+2; i <=r; i++)
      { int j = i; Item v = a[i];
        // store value at index i in a temp variable, v
        // iterating to the left of a[i]
        // shifting elements to the right 
        // until there is an element to the left of v
        // and smaller than v
        // insert v at this point
        printf("Iteration i = %d\n", i);
        while (less(v, a[j-1]))
          { printf("Iteration j = %d\n", j); 
            for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
            printf("\n");
            a[j] = a[j-1]; 
            j--; 
            for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
            printf("\n");
          }
        a[j] = v;
        printf("End of iteration\n");
        for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
        printf("\n\n");
      }
  }

main(int argc, char *argv[])
  { 
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <n-items> <randomize>\n", argv[0]);
        exit(1);
    }
    int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = malloc(N*sizeof(int));
    if (sw)
      for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else
      while (scanf("%d", &a[i]) == 1 && i < N) i++;
    insertion(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n"); 
  }
