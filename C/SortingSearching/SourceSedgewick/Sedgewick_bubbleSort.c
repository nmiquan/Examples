#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
void bubble(Item a[], int l, int r)
  { int i, j;
    for (i = l; i < r; i++) {
      printf("Iteration i = %d\n", i);
      for (j = r; j > i; j--)
        {
        printf("Iteration j = %d\n", j);
        for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
        printf("\n");
        compexch(a[j-1], a[j]); 
        for (int k = 0; k < r+1; k++) printf("%3d ", a[k]);
        printf("\n\n");
        }
      printf("----------\n");
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
    bubble(a, 0, N-1);
    for (i = 0; i < N; i++) printf("%3d ", a[i]);
    printf("\n"); 
  }
