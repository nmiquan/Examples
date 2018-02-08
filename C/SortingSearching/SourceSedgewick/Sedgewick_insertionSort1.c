// Nonadaptive insertion sort
// Moving from left to right
// Consider the element at index i
// Move the element left hand side
// Until element at i-1 is smaller than element at i

#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
void sort(Item a[], int l, int r)
  // Considering index i, from 0..n
  // elements to the left of i is sorted using index j, from i..0
  // given an element at index i, a[i]
  // a[i] is compared with element adjacent to the left
  // swap a[i] and a[i-1] if a[i] < a[i-1]
  // keep swapping until a[i] > a[i-1]
  { int i, j;
    for (i = l+1; i <= r; i++)
      for (j = i; j > l; j--)
        {
          printf("Iteration i = %d, j = %d\n", i, j);
          for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
          printf("\n");
          compexch(a[j-1], a[j]);
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
    sort(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n"); 
  }
