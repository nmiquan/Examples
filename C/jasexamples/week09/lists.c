// lists.c ... linked list functions
// Written by jas@cse, April 2017

#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

// make a new node with supplied value
// malloc new node and set its fields
// if malloc fails, print error and exit
// static == the function is private to this file
static
struct node *make_node(int val)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr,"Out of memory in newNode\n");
        exit(EXIT_FAILURE);
    }
    new->data = val;
    new->next = NULL;
    return new;
}

// display data values in a linked list
void show_list(struct node *L)
{
    if (L == NULL)
        printf("\n");
    else {
        printf(" -> %d", L->data);
        show_list(L->next);
    }
}

// count the number of Nodes in a linked list
int length(struct node *L)
{
     if (L == NULL)
         return 0;
     else
         return 1 + length(L->next);
}

// check whether a value is in the list
int search(int val, struct node *L)
{
    if (L == NULL) {
        return 0;
    }
    else if (L->data == val) {
        return 1;
    }
    else {
        return search(val, L->next);
    }
}

// check whether list sorted in ascending order
int is_sorted(struct node *L)
{
     if (L == NULL)
         return 1;
     else if (L->next == NULL)
         return 1;
     else if (L->data > L->next->data)
         return 0;
     else
         return is_sorted(L->next);
     
}

// insert a new value at the start of a linked list
struct node *insert(int val, struct node *L)
{
    struct node *new = make_node(val);
    new->next = L;
    return new;
    
}

// insert a new value at the end of a linked list
struct node *append(int val, struct node *L)
{
    if (L == NULL)
        return insert(val, L);
    else if (L->next == NULL)
        L->next = insert(val, NULL);
    else
        L->next = append(val, L->next);
    return L;
    
}

// remove a value from a linked list
// if value is not in the list, list unchanged
// if value occurs multiple times, remove first occurrence
struct node *delete(int val, struct node *L)
{
    return NULL;
}

// remove all nodes in linked list
void free_list(struct node *L)
{
     if (L == NULL)
         return;
     else {
         free_list(L->next);
         free(L);
     }
}

