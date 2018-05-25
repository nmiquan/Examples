// Written by Brad Vander Zanden 
// COMP 9024

#include <stdio.h>
#include <string.h>

// generic min function

void *min(void *element1, void *element2, int (*compare) (void *, void *)) {
    if (compare(element1, element2) < 0)
        return element1;
    else
        return element2;
}

int stringCompare(void *item1, void *item2) {
    return strcmp((char *)item1, (char *)item2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("usage: min string1 string2\n");
        return 1;
    }

    // call min to compare the two string arguments and downcast the return
    // value to a char *
    char *minString = (char *) min(argv[1], argv[2], stringCompare);

    printf("min = %s\n", minString);
    return 0;
}

