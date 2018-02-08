// list.c ... linked list ADT implementation
// Written by jas@cse, May 2017

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct node {
    int data;          // data value within Node
    struct node *next; // link to next Node
};

// make a new node with supplied value
// malloc new node and set its fields
// if malloc fails, print error and exit
// static == the function is private to this file
static
struct node *make_node(int val, struct node *next)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr,"Out of memory in newNode\n");
        exit(EXIT_FAILURE);
    }
    new->data = val;
    new->next = next;
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

// get the value in the head of the list
int list_head(struct node *L)
{
	if (L== NULL) {
		fprintf(stderr, "No head in empty list\n");
        exit(EXIT_FAILURE);
    }
    return L->data;
}

// count the number of Nodes in a linked list
int list_length(struct node *L)
{
     if (L == NULL)
         return 0;
     else
         return 1 + list_length(L->next);
}

// check whether a value is in the list
int list_search(int val, struct node *L)
{
    if (L == NULL) {
        return 0;
    }
    else if (L->data == val) {
        return 1;
    }
    else {
        return list_search(val, L->next);
    }
}

// check whether list sorted in ascending order
int list_is_sorted(struct node *L)
{
     if (L == NULL)
         return 1;
     else if (L->next == NULL)
         return 1;
     else if (L->data > L->next->data)
         return 0;
     else
         return list_is_sorted(L->next);
     
}

// insert a new value at the start of a linked list
struct node *list_insert(int val, struct node *L)
{
    return make_node(val, L);
}

// insert a new value at the end of a linked list
struct node *list_append(int val, struct node *L)
{
    if (L == NULL)
        L = list_insert(val, L);
    else if (L->next == NULL)
        L->next = list_insert(val, NULL);
    else
        L->next = list_append(val, L->next);
    return L;
}

// remove a value from a linked list
// if value is not in the list, list unchanged
// if value occurs multiple times, 
//    remove first occurrence
struct node *list_delete(int val, struct node *L)
{
    if (L == NULL)
        L = NULL;
    else if (L->data == val) {
        struct node *oldL = L; 
        L = L->next; 
        free(oldL);
    }
    else
        L->next = list_delete(val,L->next);
    return L;
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

