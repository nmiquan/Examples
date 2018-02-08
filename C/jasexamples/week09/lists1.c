// lists.c ... linked list functions
// Written by jas@cse, April 2017

#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

// make a new struct node with supplied value
// malloc new struct node and set its fields
// if malloc fails, print error and exit
// static == the function is private to this file
static
struct node *make_node(int val)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr,"Out of memory\n");
        exit(EXIT_FAILURE);
    }
    new->data = val;
    new->next = NULL;
    return new;
}

// display data values in a linked list
void show_list(struct node *L)
{
}

// count the number of Nodes in a linked list
int length(struct node *L)
{
}

// check whether a value is in the list
int search(int val, struct node *L)
{
    struct node *curr;
    curr = L;
    while (curr != NULL) {
        if (curr->data == val) return 1;
        curr = curr->next;
    }
    return 0;
}

// check whether list sorted in ascending order
int is_sorted(struct node *L)
{
}

// insert a new value at the start of a linked list
struct node *insert(int val, struct node *L)
{
    struct node *new;
    new = make_node(val);
    new->next = L;
    return new;
}

// insert a new value at the end of a linked list
struct node *append(int val, struct node *L)
{
}

// remove a value from a linked list
// if value is not in the list, list unchanged
// if value occurs multiple times, remove first occurrence
struct node *delete(int val, struct node *L)
{
    struct node *curr = L, *prev = NULL;
    if (L == NULL) return NULL;
    while (curr != NULL) {
         if (curr->data == val) break;
         prev = curr;
         curr = curr->next;
    }
    if (curr == NULL) // val not in list
        return L;
    else if (prev == NULL) { // delete first node
        L = curr->next;
        free(curr);
        return L;
    }
    else { // delete node in "middle" of list
        prev->next = curr->next;
        free(curr);
        return L;
    }  
}

// remove all nodes in linked list
void free_list(struct node *L)
{
    struct node *curr, *next;
    
    if (L == NULL) return;
   
    curr = L; next = L->next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

