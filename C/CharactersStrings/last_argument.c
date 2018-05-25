#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("I have no arguments\n");
    } else {
        printf("my last argument is %s\n", argv[argc - 1]);
    }
    return 0;
}
