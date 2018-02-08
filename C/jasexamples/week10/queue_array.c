// queue_array.c ... implementation of Queue ADT
// - uses a fixed size array, with circular indexing
// Written by jas@cse

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Data structure representation of Queue

#define MAX 2048

struct queue {
    int elements[MAX];  // contents of Queue
    int front;          // index to first element
    int back;           // index to last element
    int length;         // number of elements
}

// Implementation of operations on Queue
// All functions assume queue parm is valid

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
    new->first = new->last = new->size = 0;
    return new;
}

// free a queue
void queue_free(queue_t queue)
{
    free(queue);
}

// add new item to queue
void queue_enqueue(queue_t queue, int item)
{
    if (queue->size == MAX) fatal("Queue overflow");
    queue->back++;
    queue->size++;
    queue->elements[queue->back] = item;
}

// remove next item from queue and return it
int queue_dequeue(queue_t queue)
{
}

// return true if queue is empty
int queue_is_empty(queue_t queue)
{
    return(queue->size == 0);
}

// return next item from queue but don't remove it
int queue_front(queue_t queue)
{
    if (queue == NULL) fatal("Invalid queue");
    
}

// return number elements in queue
int queue_size(queue_t queue)
{
    return queue->size;
}

// display contents of queue
void queue_show(queue_t queue)
{
    
}

