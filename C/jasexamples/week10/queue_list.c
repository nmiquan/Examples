// queue_list.c ... implementation of Queue ADT
// - uses a linked list representation
// Written by jas@cse

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Data structure representation of Queue

typedef struct node *link_t;

struct node {
    int    element;  // value in Node
    link_t next;     // link to next Node
}

struct queue {
    int elements[MAX];  // contents of Queue
    int length;         // number of elements
}

// Implementation of operations on Queue

// print a message and give up
static
void fatal(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// create a new queue
queue_t queue_create(void)
{
    struct queue *new;
    new = malloc(sizeof (struct queue));
    if (new == NULL) fatal("Out of memory");
    // TODO initialisations
    return new;
}

// free a queue
void queue_free(queue_t queue)
{
}

// add new item to queue
void queue_enqueue(queue_t queue, int item)
{
}

// remove next item from queue and return it
int queue_dequeue(queue_t queue)
{
}

// return true if queue is empty
int queue_is_empty(queue_t queue)
{
}

// return next item from queue but don't remove it
int queue_front(queue_t queue)
{
}

// return number elements in queue
int queue_size(queue_t queue)
{
}

// display contents of queue
void queue_show(queue_t queue)
{
    
}

