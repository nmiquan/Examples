#include <stdio.h>
#define MAX_PERSON 4096

void printManyMessages(int n, char nam[]);
void printMessages(char name[]);

int main(int argc, char *argv[]) {
    int n, x;
    char person[MAX_PERSON];
    printf("Person's name? ");
    person[0] = '\0';
    fgets(person, MAX_PERSON, stdin);
    x = 0;
    while (person[x] != '\n' && person[x] != '\0') {
        x = x + 1;
    }
    person[x] = '\0';
    printManyMessages(1, person);
    printf("Repeat this how many times? ");
    scanf("%d", &n);
    printManyMessages(n, person);
    return 0;
}

void printManyMessages(int n, char nam[]) {
    while (n > 0) {
        printMessages(nam);
        n = n - 1;
    }
}

void printMessages(char name[]) {
   printf("%s is good\n", name);
   printf("%s is great\n", name);
   printf("We all love %s\n", name);
}
