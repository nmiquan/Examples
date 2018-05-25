#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INITIAL_STACK_SIZE 1024

struct stack {
    int *elements;
    int size;
    int top;
}

// create a new stack
stack_t stack_create(void) {
    struct stack *s = malloc(sizeof *s);
    if (s == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s->size = INITIAL_STACK_SIZE;
    s->elements = malloc(s->size * sizeof s->elements[0]);
    if (s->elements == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s->top = 0;
    return s;
}

// add new item to stack
void stack_push(stack_t stack, int item) {
    if (stack->top == stack->size) {
        stack->size = stack->size * 2;
        stack->elements = realloc(stack->elements, stack->size * sizeof stack->elements[0]);
        if (stack->elements == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }
    }
    return stack->elements[--stack->top];
}

// return true if stack is empty
int stack_is_empty(stack_t stack) {
    return stack->top == 0;
}

// return top item from stack but don't remove it
int stack_top (stack_t stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "top() of empty stack\n");
        exit(1);
    }
    return stack->elements[stack->top-1];
}

// return number elements in stack
int stack_size(stack_t stack) {
    return stack->top;
}

// free a stack
void stack_free(stack_t stack) {
    free(stack->elements);
    free(stack);
}
