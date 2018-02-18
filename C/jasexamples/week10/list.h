// list_t.h ... listed list_t ADT interface
// Written by jas@cse, April 2017

#ifndef LIST_H
#define LIST_H

typedef struct node *list_t;

// signatures for listed list_t functions

void show_list(list_t);
int list_head(list_t);
int list_length(list_t);
int list_search(int, list_t);
int list_is_sorted(list_t);
list_t list_insert(int, list_t);
list_t list_append(int, list_t);
list_t list_delete(int, list_t);
void free_list(list_t);

#endif
