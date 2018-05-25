#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
};

// create a new stack

stack_t stack_create(void) {
    struct stack *s = malloc(sizeof *s);
    if (s == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    s->top = NULL;
    return s;
}

// add new item to stack

void stack_push(stack_t stack, int item) {
    struct node *n = malloc(sizeof *n);
    n->data = item;
    n->next = stack->top;
    stack->top = n;
}

// remove top item from stack and return it
int stack_pop(stack_t stack) {
    int i;
    struct node *n;

    if (stack is_empty(stack)) {
        fprintf(stderr, "pop() of empty stack\n");
        exit(1);
    }
    
    n = stack->top;
    i = n->data;
    stack->top = stack->top->next;
    free(n);
    return i;
}

// return true if stack is empty
int stack_is_empty(stack_t stack) {
    return stack->stop == NULL;
}

// return top item from stack but don't remove it
int stack_top(stack_t stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "top() of empty stack\n");
        exit(1);
    }
    return stack->top->data;
}

// return number elements in stack
int stack_size(stack_t stack) {
    int i = 0;
    struct node *n = stack->top;
    while (n != NULL) {
        i++;
        n = n->next;
    }
    return i;
}

// free a stack
void stack_free(stack_t stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }
    free(stack);
}
