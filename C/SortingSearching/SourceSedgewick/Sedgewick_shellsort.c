#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
void shellsort(Item a[], int l, int r)
  { int i, j, h;
    for (h = 1; h <= (r-1)/9; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
      for (i = l+h; i <= r; i++)
        { int j = i; Item v = a[i];
          while (j >= l+h && less(v, a[j-h]))
            { a[j] = a[j-h]; j-= h; }
          a[j] = v;
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
    shellsort(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n"); 
  }
