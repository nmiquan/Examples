#include <stdio.h>

void main(int argc, char *argv[]) {
    int ctr;
    for(ctr = 0; ctr < argc; ctr++) {
        puts(argv[ctr]);
    }
}
