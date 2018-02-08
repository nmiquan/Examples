// Example from Moffat, Alistair
// Programming, problem solving, & abstraction with C

#include <stdio.h>
#include <string.h>

int is_sorted(void *A, size_t nelem, size_t size, int (*cmp) (void*, void*));

int double_ascending(void *v1, void *v2) {
    double *d1 = v1, *d2 = v2;
    if (*d1 < *d2) return -1;
    if (*d1 > *d2) return +1;
    return 0;
}

int string_descending(void *v1, void *v2) {
    char **s1 = v1, **s2 = v2;
    return -strcmp(*s1, *s2);
}

int is_sorted(void *A, size_t nelem, size_t size, int (*cmp) (void*, void*)) {
    char *Ap = (char *)A; // why is double pointer converted to char pointer?
    while (nelem > 1) {
        if (cmp(Ap, Ap+size) > 0) {
            /* these two are out of order */
            return 0;
        }
        Ap += size;
        nelem -= 1;
    }
    /* all elements have been checked, and are ok */
    return 1;
}

int main(int argc, char *argv[]) {
    double X[] = {1.87, 3.43, 7.64, 7.68, 8.16, 9.86};
    char *S[] = {"wombat", "wallaby", "quoll", "quokka", "koala", "kangaroo", "goanna", "bilby"};
    if (is_sorted(X, sizeof(X)/sizeof(*X), sizeof(*X), double_ascending)) {
        printf("Array X is ascending\n");
    }
    if (is_sorted(S, sizeof(S)/sizeof(*S), sizeof(*S), string_descending)) {
        printf("Array S is descending\n");
    }
    return 0;
}


