#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]){
    char line[MAX_LINE];
    int n;

    printf("Enter a number: ");
    fgets(line, MAX_LINE, stdin);
    n = atoi(line);
    printf("You entered %d\n", n);
    return 0;
}
