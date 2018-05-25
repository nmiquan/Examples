// lists.h ... linked list definitions
// Written by jas@cse, April 2017

// linked list data types

struct node {
    int          data; // data value in Node
    struct node *next; // pointer to following Node
};

// signatures for linked list functions

void show_list(struct node *);
int length(struct node *);
int search(int, struct node *);
int is_sorted(struct node *);
struct node *insert(int, struct node *);
struct node *append(int, struct node *);
struct node *delete(int, struct node *);
void free_list(struct node *);

