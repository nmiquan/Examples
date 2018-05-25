#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 2048

struct stack {
    int elements[MAX];
    int top;
}

// create a new stack 
stack_t stack_create(void) {
    struct stack *s = malloc(sizeof *s);
    if (s == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s->top = 0;
    return s;
}

// add new item to stack
void stack_push(stack_t stack, int item) {
    if (stack->top == MAX) {
        fprintf(stderr, "push() exceeds maximum size %d\n", MAX);
        exit(1);
    }
    stack->elements[stack->top] = item;
    stack->top++;
}

// remove top item from stack and return it
int stack_pop(stack_t stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "pop() of empty stack\n");
        exit(1);
    }
    return stack->elements[--stack->top];
}

// return true if stack is empty
int stack_is_empty(stack_t stack) {
    return stack->top == 0;
}

// return top item from stack but don't remove it
int stack_top(stack_t stack) {
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
    free(stack);
}
