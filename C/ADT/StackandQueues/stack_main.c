#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    stack_t s;
    s = stack_create();
    stack_push(s, 10);
    stack_push(s, 11);
    stack_push(s, 12);
    printf("%d\n", stack_size(s)); // prints 3
    printf("%d\n", stack_top(s)); // prints 12
    printf("%d\n", stack_pop(s)); // prints 12
    printf("%d\n", stack_pop(s)); // prints 11
    printf("%d\n", stack_pop(s)); // prints 10
    return 0;
}

