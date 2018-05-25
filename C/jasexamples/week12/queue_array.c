// queue_array.c ... implementation of Queue ADT
// - uses a fixed size array, with circular indexing
// Written by jas@cse

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Data structure representation of Queue

// typedef struct queue *queue_t;

#define MAX 4

struct queue {
    int elements[MAX];  // contents of Queue
    int first;          // index to first element
    int last;           // index to last element
    int size;           // number of elements
};

// Implementation of operations on Queue
// All functions assume queue param is valid

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
    for (int i = 0; i < MAX; i++)
        new->elements[i] = 0;
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
    if (queue->size > 0) {
        queue->last = (queue->last + 1) % MAX;
    }
    queue->size++;
    queue->elements[queue->last] = item;
}

// remove item from front of queue and return it
int queue_dequeue(queue_t queue)
{
    if (queue->size == 0) fatal("Queue underflow");
	int val = queue->elements[queue->first];
    queue->size--;
    queue->first = (queue->first + 1) % MAX;
    if (queue->size == 0)
        queue->first = queue->last = 0;
    return val;
}

// return true if queue is empty
int queue_is_empty(queue_t queue)
{
    return (queue->size == 0);
}

// return item at front of queue but don't remove it
int queue_front(queue_t queue)
{
    if (queue->size == 0) fatal("No front");
    return (queue->elements[queue->first]);
}

// return number elements in queue
int queue_size(queue_t queue)
{
    return queue->size;
}

// display contents of queue
void queue_show(queue_t q)
{
#ifdef DBUG
    printf("(%d,%d,%d) ", q->first, q->last, q->size);
#endif
    if (q->size == 0)
        printf("EMPTY");
    else {
        printf("FIRST{");    
        int i, j = q->first;
        for (i = 0; i < q->size; i++) {
            printf(" %d",  q->elements[j]);
            j = (j+1) % MAX;
        }
        printf(" }LAST");
    }
}

